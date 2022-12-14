#!/usr/bin/env lua

local mtkwifi = require("mtkwifi")


--ifname = arg[1]

--local signal = require("posix.signal")

--signal.signal(signal.SIGINT, function(signum)
--  io.write("\n")
  -- put code to save some stuff here
--  os.exit(128 + signum)
--end)



function Sleep(n)
    os.execute("sleep " .. n)
end


function Checkstat(ifname)
    local iwapcli = mtkwifi.read_pipe("iwconfig "..ifname.." | grep ESSID 2>/dev/null")
    local ssid = string.match(iwapcli, "ESSID:\"(.*)\"")
    if not ssid or ssid == "" then
        return false
    else
        return true
    end
end

function split02(s, p)

    local rt= {}
    string.gsub(s, '[^'..p..']+', function(w) table.insert(rt, w) end )
    return rt

end
function split03(str, sep)
    local sep, fields = sep or ":", {}
    local pattern = string.format("([^%s]+)", sep)
    str:gsub(pattern, function (c) fields[#fields + 1] = c end)
    return fields
end

--function Split(str, delim, maxNb)  
function split0(str, delim)  
    maxNb=10
    -- Eliminate bad cases...  
    if string.find(str, delim) == nil then 
        return { str } 
    end 
    if maxNb == nil or maxNb < 1 then 
        maxNb = 0    -- No limit  
    end 
    local result = {} 
    local pat = "(.-)" .. delim .. "()"  
    local nb = 0 
    local lastPos  
    for part, pos in string.gfind(str, pat) do 
        nb = nb + 1 
        result[nb] = part  
        lastPos = pos  
        if nb == maxNb then break end 
    end 
    -- Handle the last field  
    if nb ~= maxNb then 
        result[nb + 1] = string.sub(str, lastPos)  
    end 
    return result  
end 

function getchannel(ifname)
    local iwapcli = mtkwifi.read_pipe("iwconfig "..ifname.." | grep Channel 2>/dev/null")
    local s1 = split0(iwapcli,"Channel=")[2]
    if not s1 then
        return ""
    end
    local s2 = split0(s1," ")[1]
    if not s2 then
        return ""
    end
    return s2
end

--print("dkfj "..getchannel("apcli0"))
--os.exit()

function scan(ifname,ssid)
    local aplist = mtkwifi.scan_ap(ifname)
    local convert="";
    for i=1, #aplist do
        print("efdf "..ssid.."dflks "..aplist[i]["ssid"].." channel "..aplist[i]["channel"])
        if aplist[i]["ssid"] == ssid then
            return aplist[i]["channel"]
        end
    end
    return ""
end

if mtkwifi.exists("/tmp/apcli_daemon.runing") then   
--    os.exit(0)
end

os.execute("echo 1>/tmp/apcli_daemon.runing")

while (true) 
do
    print "dkjfelj"

    local interface="apcli0"
    local cfgs = mtkwifi.load_profile("/etc/wireless/mediatek/mt7915.dbdc.b0.dat")

    if (cfgs.ApCliEnable == "1") and (cfgs.AutoChannelSelect == "3") then
        if not Checkstat(interface) then
            channel=scan(interface,cfgs.ApCliSsid)
            print("dkjfeljddfe"..channel)
            print("dkfd"..getchannel(interface))
            if channel ~= ""  then
                if channel ~= getchannel(interface) then
                    os.execute("iwpriv "..interface.." set Channel="..channel)
                end
            end
        end
    end

    
    local interface="apclix0"
    local cfgs = mtkwifi.load_profile("/etc/wireless/mediatek/mt7915.dbdc.b1.dat")

    if (cfgs.ApCliEnable == "1") and (cfgs.AutoChannelSelect == "3") then
        if not Checkstat(interface) then
            channel=scan(interface,cfgs.ApCliSsid)
            print("dkjfeljddfe"..channel)
            print("dkfd"..getchannel(interface))
            if channel ~= ""  then
                if channel ~= getchannel(interface) then
                    os.execute("iwpriv "..interface.." set Channel="..channel)
                end
            end
        end
    end
    Sleep(5)
    print "dkjfeljddfe"
 --   break
end


os.execute("rm -f /tmp/apcli_daemon.runing")


return
