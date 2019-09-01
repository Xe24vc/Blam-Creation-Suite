#pragma once

/*
   This file has been generated by IDA.
   It contains local type definitions from
   the type library 'MCC-Win64-Shipping.exe'
*/

#define __int8 char
#define __int16 short
#define __int32 int
#define __int64 long long

#include "input_types.h"

struct _RTL_CRITICAL_SECTION_DEBUG;
struct IGameEngineOld;
struct s_game_launch_data;

typedef void(NullSubFunc)();
typedef __int64(ZeroSubFunc)();

struct c_game_engine_variant;
struct __declspec(align(8)) c_game_engine_variant_vtbl
{
	__int64(__fastcall* Member00)(c_game_engine_variant*);
	void* Member01;
	void(__fastcall* Member02)(c_game_engine_variant*);
	__int64(__fastcall* Member03)(c_game_engine_variant*);
	void* Member04;
	void* Member05;
	void* Member06;
	void* Member07;
	void* Member08;
	void* Member09;
	void* Member10;
	void* Member11;
	void(__fastcall* initialize_for_new_map)(c_game_engine_variant*, __int64, c_game_engine_variant**);
	void* Member13;
	void* Member14;
	__int64(__fastcall* Member15)(c_game_engine_variant*);
	void* Member16;
	__int64(__fastcall* Member17)(c_game_engine_variant*, _QWORD, _QWORD);
	void* Member18;
	void* Member19;
	void* Member20;
	void* Member21;
	unsigned __int8(__fastcall* Member22)(c_game_engine_variant*, __int64, __int64*, unsigned __int64);
};

struct c_game_engine_variant
{
	c_game_engine_variant_vtbl* __vftable /*VFT*/;
	BYTE data[64504];
};

struct s_game_variant
{
	DWORD game_engine_index;
	c_game_engine_variant game_engine_variant;
};

struct s_map_variant
{
	BYTE data[55724];
};

struct ISaveFilmMetadata;
struct /*VFT*/ ISaveFilmMetadata_vtbl
{
	__int64(__fastcall* Member00)(ISaveFilmMetadata*);
	__int64(__fastcall* Member01)(ISaveFilmMetadata*);
	__int64(__fastcall* GetMapId)(ISaveFilmMetadata*);
	BYTE* (__fastcall* Member03)(ISaveFilmMetadata*);
	BYTE* (__fastcall* Member04)(ISaveFilmMetadata*);
	BYTE* (__fastcall* Member05)(ISaveFilmMetadata*);
	void(__fastcall* Free)(ISaveFilmMetadata*);
};
struct ISaveFilmMetadata
{
	ISaveFilmMetadata_vtbl* __vftable /*VFT*/;
	BYTE data[128936];
};

struct IMapVariant;
struct /*VFT*/ IMapVariant_vtbl
{
	__int64(__fastcall* GetMCCMapId)(IMapVariant*);
	bool(__fastcall* Member01)(IMapVariant*);
	BYTE* (__fastcall* Member02)(IMapVariant*);
	BYTE* (__fastcall* Member03)(IMapVariant*);
	__int64(__fastcall* Member04)(IMapVariant*, wchar_t*);
	__int64(__fastcall* Member05)(IMapVariant*, wchar_t*);
	BYTE* (__fastcall* Member06)(IMapVariant*, struct s_unknown*);
	bool(__fastcall* Member07)(IMapVariant*, struct s_unknown*);
	bool(__fastcall* Member08)(IMapVariant*, struct s_unknown*);
	bool(__fastcall* Member09)(IMapVariant*, struct content_item_map_variant*, size_t*);
	void(__fastcall* Free)(IMapVariant*);
};
struct IMapVariant
{
	IMapVariant_vtbl* __vftable /*VFT*/;
	s_map_variant MapVariant;
	BYTE data[29484];
};

struct IGameVariant;
struct /*VFT*/ IGameVariant_vtbl
{
	BYTE* (__fastcall* Member00)(IGameVariant*);
	BYTE* (__fastcall* Member01)(IGameVariant*);
	__int64(__fastcall* Member02)(IGameVariant*, wchar_t*);
	__int64(__fastcall* Member03)(IGameVariant*, wchar_t*);
	BYTE* (__fastcall* Member04)(IGameVariant*);
	__int64(__fastcall* Member05)(IGameVariant*);
	__int64(__fastcall* Member06)(IGameVariant*, struct s_unknown*);
	bool(__fastcall* IsSandboxVariant)(IGameVariant*);
	char(__fastcall* Member08)(IGameVariant*);
	__int64(__fastcall* Member09)(IGameVariant*);
	IGameVariant* (__fastcall* Create)(IGameVariant*);
	__int64(__fastcall* Member11)(IGameVariant*, struct s_unknown*, struct s_unknown*);
	__int64(__fastcall* Member12)(IGameVariant*, struct s_unknown*, struct s_unknown*);
	bool(__fastcall* Member13)(IGameVariant*, struct s_unknown*, struct s_unknown*);
	bool(__fastcall* Member14)(IGameVariant*, struct s_unknown*, struct s_unknown*);
	bool(__fastcall* Member15)(IGameVariant*, struct s_unknown*, struct s_unknown*);
	bool(__fastcall* Member16)(IGameVariant*, struct s_unknown*);
	bool(__fastcall* Member17)(IGameVariant*, struct s_unknown*);
	bool(__fastcall* Member18)(IGameVariant*, struct content_item_game_variant*, size_t*);
	void(__fastcall* Free)(IGameVariant*);
};
struct IGameVariant
{
	IGameVariant_vtbl* __vftable /*VFT*/;
	s_game_variant GameVariant;
	BYTE data[22060];
};

struct IDataAccess;
struct IDataAccess_vtbl
{
	struct IMapVariant* (__fastcall* CreateMapVariantFromFile)(IDataAccess*, /*struct content_item_map_variant **/char*, size_t);
	struct IMapVariant* (__fastcall* CreateMapVariantFromMCCMapId)(IDataAccess*, __int64);
	struct IMapVariant* (__fastcall* CreateMapVariant)(IDataAccess*, struct s_map_variant*);
	struct IGameVariant* (__fastcall* CreateGameVariantFromFile)(IDataAccess*, /*struct content_item_game_variant **/char*, size_t);
	struct IGameVariant* (__fastcall* CreateGameVariant)(IDataAccess*, struct s_game_variant*);
	bool(__fastcall* Member05)(IDataAccess*, struct s_unknown*, void*);
	struct ISaveFilmMetadata* (__fastcall* CreateSaveFilmMetadataFromFile)(IDataAccess*, /*struct content_item_film_description **/char*, size_t);
	void(__fastcall* Free)(IDataAccess*);
};

struct IDataAccess
{
	IDataAccess_vtbl* __vftable /*VFT*/;
	void* c_heap_allocation;
	void* function1;
	void* c_heap_allocation_size;
	void* function3;

	__int64 CreateMapVariantFromFile(char* content_item_map_variant, size_t file_length)
	{
		return (__int64)__vftable->CreateMapVariantFromFile(this, content_item_map_variant, file_length);
	}
	__int64 CreateGameVariantFromFile(char* content_item_game_variant, size_t file_length)
	{
		return (__int64)__vftable->CreateGameVariantFromFile(this, content_item_game_variant, file_length);
	}
};

/* 4 */
typedef struct _GUID GUID;

/* 23 */
typedef _RTL_CRITICAL_SECTION_DEBUG* PRTL_CRITICAL_SECTION_DEBUG;


/* 28 */
typedef void* HANDLE;

/* 29 */
typedef unsigned __int64 ULONG_PTR;



/* 20 */
typedef unsigned __int16 WORD;


/* 25 */
typedef _LIST_ENTRY LIST_ENTRY;



/* 522 */
struct UnknownStringType
{
	char data[48];
};






//struct s_game_launcher
//{
//	_DWORD dword0;
//	_DWORD dword4;
//	s_game_launch_data GameLaunchData;
//};
//static_assert(sizeof(s_game_launcher) == 0x2B7D0, "");

enum e_load_state
{
	_load_state_initial,
	_load_state_create_local_squad,
	_load_state_select_game_mode,
	_load_state_saved_film,
	_load_state_campaign,
	_load_state_previous_game_state,
	_load_state_multiplayer,
	_load_state_survival,
	_load_state_wait_for_party,
	_load_state_join_remote_squad,
	_load_state_unused,
	_load_state_start_game,
	_load_state_terminate,

	k_number_of_load_states,
	k_load_state_invalid = -1,
};

enum e_peer_property
{
	_peer_property_none,
	_peer_property_network_configuration_unavailable,
	_peer_property_file_manifest_unavailable,
	_peer_property_banhammer_unavailable,
	_peer_property_player_stats_unavailable,
	_peer_property_lsp_stats_unavailable,
	_peer_property_master_hopper_file_unavailable,
	_peer_property_hopper_specific_file_unavailable,
	_peer_property_network_configuration_pending,
	_peer_property_file_manifest_pending,
	_peer_property_dlc_map_manifest_pending,
	_peer_property_dlc_enumeration_pending,
	_peer_property_banhammer_pending,
	_peer_property_player_stats_pending,
	_peer_property_lsp_stats_pending,
	_peer_property_master_hopper_file_pending,
	_peer_property_hopper_specific_file_pending,
	_peer_property_no_map_selected,
	_peer_property_no_game_selected,
	_peer_property_map_load_failure,
	_peer_property_map_load_precaching,
	_peer_property_invalid_film_selected,
	_peer_property_no_film_selected,
	_peer_property_too_many_teams,
	_peer_property_all_observers,
	_peer_property_too_many_for_local_coop,
	_peer_property_too_many_for_net_coop,
	_peer_property_incompatible_for_net_coop,
	_peer_property_account_not_online_enabled,
	_peer_property_all_profiles_must_by_live_gold,
	_peer_property_must_be_connect_to_live,
	_peer_property_must_be_in_a_live_lobby,
	_peer_property_invalid_hopper,
	_peer_property_squad_too_large,
	_peer_property_squad_too_small,
	_peer_property_too_many_local_players,
	_peer_property_too_few_local_players,
	_peer_property_non_local_players_exist,
	_peer_property_games_played_too_low,
	_peer_property_games_played_too_high,
	_peer_property_grade_too_low,
	_peer_property_grade_too_high,
	_peer_property_access_bit_not_set,
	_peer_property_unpaid_in_paid_hopper,
	_peer_property_paid_in_unpaid_hopper,
	_peer_property_guest_not_allowed,
	_peer_property_player_missing_files,
	_peer_property_player_missing_required_maps,
	_peer_property_player_banned_from_matchmaking,
	_peer_property_matchmaking_ban_quitting,
	_peer_property_not_yet_start_time,
	_peer_property_end_time_has_passed,
	_peer_property_arena_hopper_no_longer_available,
	_peer_property_hd_required_for_playlist,
	_peer_property_custom_games_are_disabled,
	_peer_property_multiplayer_split_screen,
	_peer_property_no_live_in_live_lobby,
	_peer_property_must_have_live_for_alpha,
	_peer_property_only_one_player_in_theater_alpha,
	_peer_property_theater_too_many_players,
	_peer_property_theater_must_have_hard_drive,
	_peer_property_theater_leader_must_be_host,
	_peer_property_theater_all_not_compatible,
	_peer_property_too_many_players_in_forge,
	_peer_property_user_content_not_permitted,
	_peer_property_coop_player_missing_hdd,
	_peer_property_coop_player_hdd_mismatch,
	_peer_property_coop_player_language_mismatch,
	_peer_property_invalid_film_language,
	_peer_property_controller_not_attached,
	_peer_property_survival_too_many_players,
	_peer_property_queued_join_expected,
	_peer_property_map_and_game_incompatible,

	k_number_of_peer_properties
};

enum e_scenario_type : int
{
	_scenario_type_none,
	_scenario_type_campaign,
	_scenario_type_multiplayer,
	_scenario_type_mainmenu,
	_scenario_type_shared,
	_scenario_type_shared_campaign,
	_scenario_type_unused5,
	_scenario_type_unused6,

	k_number_of_scenario_types,
};

struct s_game_options
{
	e_scenario_type scenario_type;
	BYTE game_simulation[8];
	WORD frame_limit;
	WORD unknownE;
	BYTE game_instance[8];
	DWORD random_seed;
	DWORD language;
	BYTE campaign_id;
	DWORD determinism_version;
	BYTE game_variant[0xFC04];
	DWORD map_id;
	BYTE unknownFC30[4];
	char scenario_path[260];
	BYTE unknownFE94[129];
	BYTE game_is_playtest;
	BYTE unknownFF16[18];
	DWORD campaign_difficulty;
	BYTE unknownFF2C[299];
	BYTE map_variant[0xD9AC];
	BYTE unknown1DA03[4345];
};
static_assert(sizeof(s_game_options) == 0x1E9A0, "");

struct s_game_state_header
{
	DWORD* unknown0;
	char source_file[256];
	char build[32];
	DWORD unknown108;
	BYTE unknown10C[4];
	s_game_options game_options;
	BYTE scenario_game_state[24];
	BYTE unknown24C90[64];
};
static_assert(sizeof(s_game_state_header) == 0x1EB28, "");

struct s_game_globals
{
	BYTE unknown0[16];
	s_game_options game_options;
	BYTE unknown1E9B0[1584];
};
static_assert(sizeof(s_game_globals) == 0x1EFE0, "");

template<typename T>
struct point3d
{
	T X, Y, Z;
};

template<typename T>
struct vector3d
{
	T I, J, K;
};

struct s_camera
{
	point3d<float> Position;
	point3d<float> PositionShift;
	float Look;
	float LookShift;
	float Depth;
	float FOVRadians;
	vector3d<float> Forward;
	vector3d<float> Up;
	vector3d<float> Direction;

	//...

	bool Compare(s_camera* camera)
	{
		auto position = Position.X != camera->Position.X || Position.Y != camera->Position.Y || Position.Z != camera->Position.Z;
		auto positionShift = PositionShift.X != camera->PositionShift.X || PositionShift.Y != camera->PositionShift.Y || PositionShift.Z != camera->PositionShift.Z;
		auto look = Look != camera->Look;
		auto lookShift = LookShift != camera->LookShift;
		auto depth = Depth != camera->Depth;
		auto fovRadians = FOVRadians != camera->FOVRadians;
		auto forward = Forward.I != camera->Forward.I || Forward.J != camera->Forward.J || Forward.K != camera->Forward.K;
		auto up = Up.I != camera->Up.I || Up.J != camera->Up.J || Up.K != camera->Up.K;
		auto direction = Direction.I != camera->Direction.I || Direction.J != camera->Direction.J || Direction.K != camera->Direction.K;

		return position || positionShift || look || lookShift || depth || fovRadians || forward || up || direction;
	}
};

struct s_player_control_globals
{
	BYTE unknown0[0x94];
	float hLookAngle;
	float vLookAngle;
	BYTE unknown9C[0x894];
};
static_assert(sizeof(s_player_control_globals) == 0x930, "");

struct s_director_globals
{
	BYTE unknown0[0x6F0];
};
static_assert(sizeof(s_director_globals) == 0x6F0, "");