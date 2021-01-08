/*
 * Copyright (c) 2020 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */
/*
 *Summary
 */

#include <sys/util.h>
#include <logging/log.h>

LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

#define DT_DRV_COMPAT zmk_ledmap

static inline int ledmap_led_on(const struct device *dev, uint32_t led) {
    return 0;
}
static inline int ledmap_led_off(const struct device *dev, uint32_t led) {
    return 0;
}
static int ledmap_led_set_color(const struct device *dev, uint32_t led, uint8_t num_of_colors,
                                    const uint8_t *colors) {
    return 0;
}
static int ledmap_led_set_brightness(const struct device *dev, uint32_t led, uint8_t value) {
    return 0;
}
static int ledmap_led_reset(const struct device *dev) {
    return 0;
}

static int ledmap_led_init(const struct device *dev) {
    LOG_ERR("LEDMAP INIT");
    return 0;
}
struct zmk_ledmap_config {
    char *label;
};
struct zmk_ledmap_data {
    int num_of_led;
    int ledmap;
};
static const struct led_driver_api ledmap_api = {
    .on = ledmap_led_on,
    .off = ledmap_led_off,
    .set_brightness = ledmap_led_set_brightness,
    .set_color = ledmap_led_set_color,
};

#define LEDMAP_INIT(inst)                                                                      \
    static struct ledmap_data ledmap_led_data_##inst;                                      \
    static const struct ledmap_config ledmap_config_##inst = {                             \
        .label = DT_INST_BUS_LABEL(inst),                                                       \
    };                                                                                             \
    DEVICE_AND_API_INIT(ledmap_led##inst, DT_INST_LABEL(inst), &ledmap_led_init,           \
                        &ledmap_led_data_##inst, &ledmap_config_##inst, POST_KERNEL,       \
                        CONFIG_LED_INIT_PRIORITY, &ledmap_api);
DT_INST_FOREACH_STATUS_OKAY(LEDMAP_INIT)
