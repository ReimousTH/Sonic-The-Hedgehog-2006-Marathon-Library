#pragma once
#include <list>

namespace Sonicteam{
	namespace Player{
		typedef struct AIMArray;
		typedef struct AnimIDMap;
		typedef struct UACSATIndexTable;


		template <typename T>
		struct Array {
			T* items;
			int count;

			T& operator[](size_t index) {
				return items[index];
			}
			int index(){
				return 0
			}
			
			
		};

	
		struct AIMArray{
			AnimIDMap* items;
			int LastItemID;
			int EndItemID;
		};

		struct AnimIDMap{
			int ID;
			int param1;
			int extra;
			float param2; //15.0
			float param3; // 15.0
			int RegAnimID;	
			float param4; // == NAN
		};
		struct UACSATIndexTable{
			char buffer[9];
		};

	
		struct CharacterStateAnimationTableStruct {
			Array<const char*> RegisteredAnimations;
			AIMArray MapAnimation;
			Array<const char*> RegisteredAnimationsHead;
			Array<UACSATIndexTable> MapAnimationHead;
		};


		//Later
		static const char* AnimationListCommon[] = {
			"wait", "wait2", "wait3", "wait4", "damage1", "damage2", "damage3", "damage_light_s", "damage_light_l", "damage_light_e",
			"down", "down_l", "down_fall", "dush", "fall", "grind_l", "grindturn_l", "jump", "jumpup", "landing", "run", "standup", "stop",
			"quickturn", "walk", "homing", "homing_after", "homing_after1", "homing_after2", "spring", "goal", "goal_l", "edge_hang",
			"edge_jump", "ottotto", "sliding", "sliding_stand", "attack", "updownreel", "tarzan_l", "tarzan_f_l", "tarzan_f2b_l", "tarzan_b_l",
			"tarzan_b2f_l", "bungee_d_l", "bungee_d2u", "bungee_u", "bungee_fly", "poll_s", "poll_l", "poll_e", "wind", "lightdash", "chainjump_s",
			"chainjump_l", "chainjump_landing", "overdrive", "overdrive_l", "chaos_spear_s", "chaos_spear_l", "chaos_spear_wait_s",
			"chaos_spear_wait_l", "chaos_blast_s", "chaos_blast_wait_l", "chaos_blast_attack_s", "chaos_blast_attack_l", "chaos_wait",
			"chaos_snap_0", "chaos_snap_1", "chaos_snap_2", "chaos_snap_3", "chaos_snap_4", "esp_w_up", "esp_w", "esp_w_to_charge", "esp_w_charge",
			"esp_w_attack", "esp_hold_s", "esp_hold_l", "esp_one_l_charge", "esp_one_l", "esp_one_r_charge", "esp_one_r", "esp_one_a",
			"esp_one_j_l_charge", "esp_one_j_l", "esp_one_j_r_charge", "esp_one_j_r", "esp_one_j_a", "esp_r_atk1", "esp_r_atk2", "esp_r_atk2a",
			"esp_r_atk3_1", "esp_r_atk3_1a", "esp_r_atk3_2", "esp_r_atk3_2a", "quake_s", "quake_s_j", "quake_l", "quake_e", "quake_roll",
			"teleport_dash_s", "teleport_dash_l", "teleport_dash_e", "jeep_ride", "jeep_ride_r", "jeep_ride_l", "jeep_damage", "jeep_damage_light",
			"jeep_back_s", "jeep_back_l", "bike_ride", "bike_ride_r", "bike_ride_l", "bike_damage", "bike_damage_light", "bike_jump_up",
			"bike_jump_down", "bike_dash", "bike_back_s", "bike_back_l", "bike_wily", "bike_brake", "hover_ride", "hover_ride_r", "hover_ride_l",
			"hover_damage", "hover_damage_light", "hover_back_s", "hover_back_l", "hover_brake", "hover_jump", "glider_ride", "glider_ride_r",
			"glider_ride_l", "glider_ride_u", "glider_ride_d", "glider_damage", "glider_damage_light", "glider_boost", "float_wait", "float_walk",
			"rainbow_ring_s", "rainbow_ring_l", "rainbow_ring_e", "fly", "fly_tired", "bomb_throw", "bomb_search_s", "bomb_search_l",
			"bomb_search_e", "pray", "stealth_end", "jump_double_0", "jump_double_1", "accel_tornado", "spinning_claw_l", "spinning_claw_e",
			"glide_s", "glide_l", "glide_e", "heat_knuckle_0", "heat_knuckle_1", "heat_knuckle_2", "screw_charge_s", "screw_charge_l", "screw_l",
			"screw_e", "screw_after", "jumpbomb", "jumpbomb_spread_l", "jumpbomb_spread_e", "climb_wait", "climb_walk", "heart_mine",
			"spinattack_s", "spinattack_l", "spinattack_e", "rodeo", "amigo_s", "amigo_l", "select_s", "select_l", "tornado_s", "tornado_ground",
			"tornado_air", "super", "piyori_l", "piyori_e", "hold", "super_fly_up", "super_fly_down", "super_fly_left", "super_fly_right",
			"lightattack_l", "store", "store_l", "chaos_attack", "chaos_attack_l", "psycho_field", "psycho_field_l", "smash3", "smash3_l",
			"launcher_r", "launcher_l", "lock_on_l", "lock_on_air_l"
		};
		static Array<const char*> RegisteredAnimationsCommon = {
			AnimationListCommon,0xCF
		
		};
		static const AIMArray AIMTableCommon[] = {
			{0}
		};


		static const CharacterStateAnimationTableStruct CharacterStateAnimationTableCommon = {
			RegisteredAnimationsCommon,
			{NULL, 0, 0},
			{NULL},
			{NULL}
		};

		
	}
}

