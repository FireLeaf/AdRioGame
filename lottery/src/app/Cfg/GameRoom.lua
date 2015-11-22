--
-- Author: OwlGame
-- Date: 2015-11-19 21:55:05
--
game_room = {}

--F fix 固定
--V variable 可变
--P pos 位置

GAME_ROOMTYPE_FP = 0 --固定位置的中奖规则

game_room["SolarSystem"] = {
	mask_sprites = {"Sprite_Mask",},
	key_pos = {"Sprite_1", "Sprite_2", "Sprite_3", "Sprite_4", "Sprite_5", "Sprite_6", "Sprite_7", "Sprite_8", },
	official_content = {
		[1] = {value = 1, texture = "SolarSystem/shuixing.png",},
		[2] = {value = 2, texture = "SolarSystem/jingxing.png",},
		[3] = {value = 3, texture = "SolarSystem/diqiu.png",},
		[4] = {value = 4, texture = "SolarSystem/huoxing.png",},
		[5] = {value = 5, texture = "SolarSystem/muxing.png",},
		[6] = {value = 6, texture = "SolarSystem/tuxing.png",},
		[7] = {value = 7, texture = "SolarSystem/tianwangxing.png",},
		[8] = {value = 8, texture = "SolarSystem/haiwangxing.png",},
	},

	award_rule = {
		award_type = GAME_ROOMTYPE_FP,
		--[0] = {}
	},
}