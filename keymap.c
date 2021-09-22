 #include QMK_KEYBOARD_H


const rgblight_segment_t PROGMEM rgb_L0_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    //{0, 3, HSV_RED},       // Light 4 LEDs, starting with LED 6
    //{3, 3, HSV_CYAN},       // Light 4 LEDs, starting with LED 12
	{0, 3, HSV_BLACK} 
 );
 
 const rgblight_segment_t PROGMEM rgb_L1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
   { 0,3, HSV_GREEN}
 );

 const rgblight_segment_t PROGMEM rgb_L2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
   { 0,3, HSV_BLUE}
 );

 const rgblight_segment_t PROGMEM rgb_L3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
   { 0,3, HSV_RED}
 );
   
 const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
   rgb_L0_layer,  // 配列0のためのダミー定義
   rgb_L1_layer,
   rgb_L2_layer,
   rgb_L3_layer
 );

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, 0));
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    rgblight_set_layer_state(3, layer_state_cmp(state, 3));
    return state;
}
// キーボード初期化後に呼ばれる関数
void keyboard_post_init_user(void) {
   //// レイヤーのLED情報を読み込み
	rgblight_layers = rgb_layers; 
	int i;
	for(i=0;i<=8;i++){
		rgblight_sethsv_at(HSV_BLACK, i); 
	}
} 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT(KC_KP_7, KC_KP_8, KC_KP_9,
               KC_KP_4, LT(1, KC_KP_5), KC_KP_6,
               KC_KP_1, KC_KP_2, KC_KP_3),

  [1] = LAYOUT(RGB_RMOD, RGB_VAI, RGB_MOD,
               RGB_HUI, RESET, RGB_SAI,
               RGB_HUD, RGB_VAD, RGB_SAD),

  [2] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS,
               KC_TRNS, KC_TRNS, KC_TRNS,
               KC_TRNS, KC_TRNS, KC_TRNS),

  [3] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS,
               KC_TRNS, KC_TRNS, KC_TRNS,
               KC_TRNS, KC_TRNS, KC_TRNS),
};
