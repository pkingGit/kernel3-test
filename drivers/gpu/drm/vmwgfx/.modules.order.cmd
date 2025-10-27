cmd_drivers/gpu/drm/vmwgfx/modules.order := {   echo drivers/gpu/drm/vmwgfx/vmwgfx.ko; :; } | awk '!x[$$0]++' - > drivers/gpu/drm/vmwgfx/modules.order
