TARGET := iphone:clang:latest:15.0
INSTALL_TARGET_PROCESSES = ShadowTrackerExtra

ARCHS = arm64 arm64e

include $(THEOS)/makefiles/common.mk

TWEAK_NAME = darkos

$(TWEAK_NAME)_FILES = Engine.mm Esp.mm Menu.mm Dumped_Offsets.cpp ESP/PubgLoad.mm ESP/HeeNoScreenShotView.m ESP/HideFunsion.m ESP/ini_rw.cpp ESP/imgui/Tools.cpp ESP/imgui/imgui.cpp ESP/imgui/imgui_draw.cpp ESP/imgui/imgui_tables.cpp ESP/imgui/imgui_widgets.cpp ESP/imgui/imgui_impl_metal.mm

$(TWEAK_NAME)_CFLAGS = -fobjc-arc -w -I. -IESP -IESP/imgui -ISDK
$(TWEAK_NAME)_CCFLAGS = -std=c++17 -fobjc-arc -w -I. -IESP -IESP/imgui -ISDK
$(TWEAK_NAME)_FRAMEWORKS = UIKit Foundation CoreGraphics Metal MetalKit QuartzCore Security

include $(THEOS_MAKE_PATH)/tweak.mk
