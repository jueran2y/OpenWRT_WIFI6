
PKG_CHECK_FORMAT_SECURITY:=0

include $(TOPDIR)/rules.mk
 
PKG_NAME:=hser2net_writekey
PKG_RELEASE:=1
PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)
 

include $(INCLUDE_DIR)/package.mk


#	dfsdfsdfs



define Package/hser2net_writekey
	SECTION:=utils
	CATEGORY:=Utilities
	TITLE:=hser2net_writekey -- prints a snarky message
endef

TARGET_CFLAGS += -I$(STAGING_DIR)/usr/include
TARGET_LDFLAGS += -L$(STAGING_DIR)/usr/lib


 
define Package/hser2net_writekey/description
    It's my first package demo.
endef
 
define Build/Prepare
	echo "Here is Package/Prepare"
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

define Package/hser2net_writekey/install
	echo "Here is Package/install"
endef
    
$(eval $(call BuildPackage,hser2net_writekey))
