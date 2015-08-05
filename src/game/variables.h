/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#ifndef GAME_VARIABLES_H
#define GAME_VARIABLES_H
#undef GAME_VARIABLES_H // this file will be included several times


// client
MACRO_CONFIG_INT(ClPredict, cl_predict, 1, 0, 1, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Predict client movements")
MACRO_CONFIG_INT(ClNameplates, cl_nameplates, 1, 0, 1, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Show name plates")
MACRO_CONFIG_INT(ClNameplatesAlways, cl_nameplates_always, 1, 0, 1, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Always show name plates disregarding of distance")
MACRO_CONFIG_INT(ClNameplatesTeamcolors, cl_nameplates_teamcolors, 1, 0, 1, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Use team colors for name plates")
MACRO_CONFIG_INT(ClNameplatesSize, cl_nameplates_size, 50, 0, 100, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Size of the name plates from 0 to 100%")
MACRO_CONFIG_INT(ClAutoswitchWeapons, cl_autoswitch_weapons, 0, 0, 1, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Auto switch weapon on pickup")

MACRO_CONFIG_INT(ClShowhud, cl_showhud, 1, 0, 1, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Show ingame HUD")
MACRO_CONFIG_INT(ClShowChatFriends, cl_show_chat_friends, 0, 0, 1, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Show only chat messages from friends")
MACRO_CONFIG_INT(ClShowfps, cl_showfps, 0, 0, 1, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Show ingame FPS counter")

MACRO_CONFIG_INT(ClAirjumpindicator, cl_airjumpindicator, 1, 0, 1, CFGFLAG_CLIENT|CFGFLAG_SAVE, "")
MACRO_CONFIG_INT(ClThreadsoundloading, cl_threadsoundloading, 0, 0, 1, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Load sound files threaded")

MACRO_CONFIG_INT(ClWarningTeambalance, cl_warning_teambalance, 1, 0, 1, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Warn about team balance")

MACRO_CONFIG_INT(ClMouseDeadzone, cl_mouse_deadzone, 300, 0, 0, CFGFLAG_CLIENT|CFGFLAG_SAVE, "")
MACRO_CONFIG_INT(ClMouseFollowfactor, cl_mouse_followfactor, 60, 0, 200, CFGFLAG_CLIENT|CFGFLAG_SAVE, "")
MACRO_CONFIG_INT(ClMouseMaxDistance, cl_mouse_max_distance, 800, 0, 0, CFGFLAG_CLIENT|CFGFLAG_SAVE, "")

MACRO_CONFIG_INT(EdShowkeys, ed_showkeys, 0, 0, 1, CFGFLAG_CLIENT|CFGFLAG_SAVE, "")

//MACRO_CONFIG_INT(ClFlow, cl_flow, 0, 0, 1, CFGFLAG_CLIENT|CFGFLAG_SAVE, "")

MACRO_CONFIG_INT(ClShowWelcome, cl_show_welcome, 1, 0, 1, CFGFLAG_CLIENT|CFGFLAG_SAVE, "")
MACRO_CONFIG_INT(ClMotdTime, cl_motd_time, 10, 0, 100, CFGFLAG_CLIENT|CFGFLAG_SAVE, "How long to show the server message of the day")

MACRO_CONFIG_STR(ClVersionServer, cl_version_server, 100, "version.teeworlds.com", CFGFLAG_CLIENT|CFGFLAG_SAVE, "Server to use to check for new versions")

MACRO_CONFIG_STR(ClLanguagefile, cl_languagefile, 255, "", CFGFLAG_CLIENT|CFGFLAG_SAVE, "What language file to use")

MACRO_CONFIG_INT(PlayerUseCustomColor, player_use_custom_color, 0, 0, 1, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Toggles usage of custom colors")
MACRO_CONFIG_INT(PlayerColorBody, player_color_body, 65408, 0, 0xFFFFFF, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Player body color")
MACRO_CONFIG_INT(PlayerColorFeet, player_color_feet, 65408, 0, 0xFFFFFF, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Player feet color")
MACRO_CONFIG_STR(PlayerSkin, player_skin, 24, "default", CFGFLAG_CLIENT|CFGFLAG_SAVE, "Player skin")

MACRO_CONFIG_INT(UiPage, ui_page, 6, 0, 10, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Interface page")
MACRO_CONFIG_INT(UiToolboxPage, ui_toolbox_page, 0, 0, 2, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Toolbox page")
MACRO_CONFIG_STR(UiServerAddress, ui_server_address, 64, "localhost:8303", CFGFLAG_CLIENT|CFGFLAG_SAVE, "Interface server address")
MACRO_CONFIG_INT(UiScale, ui_scale, 100, 50, 150, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Interface scale")
MACRO_CONFIG_INT(UiMousesens, ui_mousesens, 100, 5, 100000, CFGFLAG_SAVE|CFGFLAG_CLIENT, "Mouse sensitivity for menus/editor")

MACRO_CONFIG_INT(UiColorHue, ui_color_hue, 160, 0, 255, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Interface color hue")
MACRO_CONFIG_INT(UiColorSat, ui_color_sat, 70, 0, 255, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Interface color saturation")
MACRO_CONFIG_INT(UiColorLht, ui_color_lht, 175, 0, 255, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Interface color lightness")
MACRO_CONFIG_INT(UiColorAlpha, ui_color_alpha, 228, 0, 255, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Interface alpha")

MACRO_CONFIG_INT(GfxNoclip, gfx_noclip, 0, 0, 1, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Disable clipping")

// server
MACRO_CONFIG_INT(SvWarmup, sv_warmup, 0, 0, 0, CFGFLAG_SERVER, "Number of seconds to do warmup before round starts")
MACRO_CONFIG_STR(SvMotd, sv_motd, 900, "", CFGFLAG_SERVER, "Message of the day to display for the clients")
MACRO_CONFIG_INT(SvTeamdamage, sv_teamdamage, 0, 0, 1, CFGFLAG_SERVER, "Team damage")
MACRO_CONFIG_STR(SvMaprotation, sv_maprotation, 768, "", CFGFLAG_SERVER, "Maps to rotate between")
MACRO_CONFIG_INT(SvRoundsPerMap, sv_rounds_per_map, 1, 1, 100, CFGFLAG_SERVER, "Number of rounds on each map before rotating")
MACRO_CONFIG_INT(SvRoundSwap, sv_round_swap, 1, 0, 1, CFGFLAG_SERVER, "Swap teams between rounds")
MACRO_CONFIG_INT(SvPowerups, sv_powerups, 1, 0, 1, CFGFLAG_SERVER, "Allow powerups like ninja")
MACRO_CONFIG_INT(SvScorelimit, sv_scorelimit, 20, 0, 1000, CFGFLAG_SERVER, "Score limit (0 disables)")
MACRO_CONFIG_INT(SvTimelimit, sv_timelimit, 0, 0, 1000, CFGFLAG_SERVER, "Time limit in minutes (0 disables)")
MACRO_CONFIG_STR(SvGametype, sv_gametype, 32, "dm", CFGFLAG_SERVER, "Game type (dm, tdm, ctf)")
MACRO_CONFIG_INT(SvTournamentMode, sv_tournament_mode, 0, 0, 1, CFGFLAG_SERVER, "Tournament mode. When enabled, players joins the server as spectator")
MACRO_CONFIG_INT(SvSpamprotection, sv_spamprotection, 1, 0, 1, CFGFLAG_SERVER, "Spam protection")

MACRO_CONFIG_INT(SvRespawnDelayTDM, sv_respawn_delay_tdm, 3, 0, 10, CFGFLAG_SERVER, "Time needed to respawn after death in tdm gametype")

MACRO_CONFIG_INT(SvSpectatorSlots, sv_spectator_slots, 0, 0, MAX_CLIENTS, CFGFLAG_SERVER, "Number of slots to reserve for spectators")
MACRO_CONFIG_INT(SvTeambalanceTime, sv_teambalance_time, 1, 0, 1000, CFGFLAG_SERVER, "How many minutes to wait before autobalancing teams")
MACRO_CONFIG_INT(SvInactiveKickTime, sv_inactivekick_time, 3, 0, 1000, CFGFLAG_SERVER, "How many minutes to wait before taking care of inactive players")
MACRO_CONFIG_INT(SvInactiveKick, sv_inactivekick, 1, 0, 2, CFGFLAG_SERVER, "How to deal with inactive players (0=move to spectator, 1=move to free spectator slot/kick, 2=kick)")

MACRO_CONFIG_INT(SvStrictSpectateMode, sv_strict_spectate_mode, 0, 0, 1, CFGFLAG_SERVER, "Restricts information in spectator mode")
MACRO_CONFIG_INT(SvVoteSpectate, sv_vote_spectate, 1, 0, 1, CFGFLAG_SERVER, "Allow voting to move players to spectators")
MACRO_CONFIG_INT(SvVoteSpectateRejoindelay, sv_vote_spectate_rejoindelay, 3, 0, 1000, CFGFLAG_SERVER, "How many minutes to wait before a player can rejoin after being moved to spectators by vote")
MACRO_CONFIG_INT(SvVoteKick, sv_vote_kick, 1, 0, 1, CFGFLAG_SERVER, "Allow voting to kick players")
MACRO_CONFIG_INT(SvVoteKickMin, sv_vote_kick_min, 0, 0, MAX_CLIENTS, CFGFLAG_SERVER, "Minimum number of players required to start a kick vote")
MACRO_CONFIG_INT(SvVoteKickBantime, sv_vote_kick_bantime, 5, 0, 1440, CFGFLAG_SERVER, "The time to ban a player if kicked by vote. 0 makes it just use kick")

/* race */
MACRO_CONFIG_INT(SvRegen, sv_regen, 0, 0, 10000, CFGFLAG_SERVER, "Set regeneration")
MACRO_CONFIG_INT(SvInfinitieAmmo, sv_infinite_ammo, 1, 0, 1, CFGFLAG_SERVER, "Enable or disable infinite ammo")
MACRO_CONFIG_INT(SvInfinitieJumping, sv_infinite_jumping, 0, 0, 1, CFGFLAG_SERVER, "Enable or disable infinite jumping")
MACRO_CONFIG_INT(SvTeleport, sv_teleport, 1, 0, 1, CFGFLAG_SERVER, "Enable or disable teleportation")
MACRO_CONFIG_INT(SvTeleportGrenade, sv_teleport_grenade, 0, 0, 1, CFGFLAG_SERVER, "Enable or disable teleport of grenade")
MACRO_CONFIG_INT(SvTeleportKill, sv_teleport_kill, 0, 0, 1, CFGFLAG_SERVER, "Teleporting one someone kills him")
MACRO_CONFIG_INT(SvTeleportStrip, sv_teleport_strip, 0, 0, 1, CFGFLAG_SERVER, "Enable or disable keeping weapon after teleporting")
MACRO_CONFIG_INT(SvRocketJumpDamage, sv_rocket_jump_damage, 0, 0, 1, CFGFLAG_SERVER, "Enable or disable rocket jump damage")
MACRO_CONFIG_INT(SvPickupRespawn, sv_pickup_respawn, 1, 0, 10, CFGFLAG_SERVER, "Time before a pickup respawn")
MACRO_CONFIG_INT(SvSpeedupMult, sv_speedup_mult, 10, 1, 100, CFGFLAG_SERVER, "Boost power by multiplication")
MACRO_CONFIG_INT(SvSpeedupAdd, sv_speedup_add, 5, -100, 100, CFGFLAG_SERVER, "Boost power")
MACRO_CONFIG_INT(SvJumperAdd, sv_jumper_add, 7, -100, 100, CFGFLAG_SERVER, "Jumper power")
MACRO_CONFIG_INT(SvGravityAdd, sv_gravity_add, 3, -100, 100, CFGFLAG_SERVER, "Gravity power")
MACRO_CONFIG_INT(SvScoreIp, sv_score_ip, 1, 0, 1, CFGFLAG_SERVER, "Adds the IPs to the recordfile")
MACRO_CONFIG_INT(SvCheckpointSave, sv_checkpoint_save, 1, 0, 1, CFGFLAG_SERVER, "Saves checkpoints to the recordfile")
MACRO_CONFIG_INT(SvEnemyDamage, sv_enemy_damage, 0, 0, 1, CFGFLAG_SERVER, "Enable damage from enemys")
MACRO_CONFIG_INT(SvHammarDamage, sv_hammer_damage, 1, 0, 1, CFGFLAG_SERVER, "Enable damage from hammer")
MACRO_CONFIG_INT(SvCountSuicide, sv_count_suicide, 0, 0, 1, CFGFLAG_SERVER, "Enable counting of suicide kills")
MACRO_CONFIG_INT(SvCountTeamkill, sv_count_teamkill, 0, 0, 1, CFGFLAG_SERVER, "Enable counting of team kills")
MACRO_CONFIG_INT(SvCountKill, sv_count_kill, 0, 0, 1, CFGFLAG_SERVER, "Enable counting of normal kills")
MACRO_CONFIG_STR(SvWhitelist, sv_whitelist, 1000, "whitelist.cfg", CFGFLAG_SERVER, "Selects whitelist file")
MACRO_CONFIG_INT(SvAutoreset, sv_autoreset, 0, 0, 1, CFGFLAG_SERVER, "Auto 'tune_reset' and 'exec autoexec.cfg' on Mapchange")
MACRO_CONFIG_INT(SvLoadEnd, sv_load_end, 0, 0, 1, CFGFLAG_SERVER, "End of race on +load")

/* watermod */
MACRO_CONFIG_INT(SvWaterGravity, sv_water_gravity, 30, -10000, 10000, CFGFLAG_SERVER, "gravty")
MACRO_CONFIG_INT(SvWaterMaxx, sv_water_maxx, 600, -10000, 10000, CFGFLAG_SERVER, "maxx")
MACRO_CONFIG_INT(SvWaterMaxy, sv_water_maxy, 450, -10000, 10000, CFGFLAG_SERVER, "maxy")
MACRO_CONFIG_INT(SvWaterFriction, sv_water_friction, 90, -10000, 10000, CFGFLAG_SERVER, "friction")
MACRO_CONFIG_INT(SvWaterInsta, sv_water_insta, 0, 0, 1, CFGFLAG_SERVER, "[Not implemented in [N]RaceRevived]insta gib")
MACRO_CONFIG_INT(SvWaterStrip, sv_water_strip, 1, 0, 1, CFGFLAG_SERVER, "[Not implemented in [N]RaceRevived]if using insta gib, strip weapon first")
MACRO_CONFIG_INT(SvWaterFreezetime, sv_water_freezetime, 60, 0, 100000, CFGFLAG_SERVER, "[Not implemented in [N]RaceRevived]if using insta gib, freeze time the hammer freezes you (50=1 sec, 100 = 2 sec, ...)")
MACRO_CONFIG_INT(SvWaterOxygen, sv_water_oxygen, 0, 0, 1, CFGFLAG_SERVER, "use oxygen")
MACRO_CONFIG_INT(SvWaterOxyDrain, sv_water_oxy_drain, 1300, -100000, 100000, CFGFLAG_SERVER, "oxygen drainage")
MACRO_CONFIG_INT(SvWaterOxyRegen, sv_water_oxy_regen, 250, -100000, 100000, CFGFLAG_SERVER, "oxygen regeneration")
MACRO_CONFIG_INT(SvWaterOxyEmoteid, sv_water_oxy_emoteid, 3, 0, 100000, CFGFLAG_SERVER, "emote id")
MACRO_CONFIG_INT(SvWaterLaserjump, sv_water_laserjump, 0, 0, 1, CFGFLAG_SERVER, "laser jumps =D")
MACRO_CONFIG_INT(SvWaterKicktime, sv_water_kicktime, 10000, 0, 10000, CFGFLAG_SERVER, "[Not implemented in [N]RaceRevived]auto kick time")
MACRO_CONFIG_INT(SvWaterRambo, sv_water_rambo, 0, 0, 1, CFGFLAG_SERVER, "easter egg")
MACRO_CONFIG_INT(SvWaterGain, sv_water_gain, 100, 0, 100000, CFGFLAG_SERVER, "speed change when accelerated by water")
//MACRO_CONFIG_INT(SvWaterReflect, sv_water_reflect, 1, 0, 1, CFGFLAG_SERVER, "reflect lasers by water")


// debug
#ifdef CONF_DEBUG // this one can crash the server if not used correctly
	MACRO_CONFIG_INT(DbgDummies, dbg_dummies, 0, 0, 15, CFGFLAG_SERVER, "")
#endif

MACRO_CONFIG_INT(DbgFocus, dbg_focus, 0, 0, 1, CFGFLAG_CLIENT, "")
MACRO_CONFIG_INT(DbgTuning, dbg_tuning, 0, 0, 1, CFGFLAG_CLIENT, "")
#endif
