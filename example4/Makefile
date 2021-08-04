# Package makefile
#

include $(TOPDIR)/rules.mk

PKG_NAME:=example4
PKG_VERSION:=0.1
PKG_RELEASE:=1

PKG_MAINTAINER:=John Doe <john.doe@example.com>
PKG_LICENSE:=CC0-1.0

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/exanoke4
	SECTION:=utils
	CATEGORY:=Utilites
	TITLE:=MCU Communication daemon
	DEPENDS:= +libc +libubox +libubus +ubusd +libblobmsg-json
endef

define Package/example4/description
    This is some dummy application
endef

TARGET_CFLAGS += -I$(STAGING_DIR)/usr/include
TARGET_LDFLAGS += -lubus

define Package/MCUDaemon/install
	$(CP) ./files/* $(1)/

	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/example4 $(1)/usr/bin/
endef

$(eval $(call BuildPackage,example4))
