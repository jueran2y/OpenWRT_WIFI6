#!/usr/bin/env lua

local mtkwifi = require("mtkwifi")

local netmode = mtkwifi.read_pipe("uci show s2ncfg.@net[0].netmode")

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

print("dke3dfiedfsd"..netmode)

if netmode then
    netmode=split0(netmode,"='")[2]
end
print("dke3dfiedfsd"..netmode)
if netmode then
    netmode=split0(netmode,"'")[1]
end
print("dke3dfiedfsd"..netmode)

if (netmode == "sta2_4") or (netmode == "sta5_8") or (netmode == "eth") then
    os.execute("ifconfig br-lan down ")
    os.execute("ifconfig eth0 down ")
    return
end
if (netmode == "ap2_4") or (netmode == "ap5_8") or (netmode == "ap2_4ap5_8") then
    print("ferj3idf")
    os.execute("ifconfig apcli0 down ")
    os.execute("ifconfig apclix0 down ")
    os.execute("ifconfig eth1 down ")
    return
end

return
