[N]RaceRevived. A [N]Race ported of 0.6 by Sadale

Features:
* fully compatible with [N]Race maps and settings
* fast download implemented
* loads .cfg file per map-based. e.g. if you open maps/foo.map, then maps/foo.cfg is automatically loaded
* wlist now has IPv6 support

Known issues:
* sv_count_suicide = 1, sv_count_kill = 0. => suicide earns you score
* sv_pickup_respawn doesn't set the respawn period. It sets the respawn period multiplier.
* sv_water_kicktime are unimplemented because they are not even implemented in the original [N]Race
* sv_water_insta, sv_water_strip, sv_water_freezetime are unimplemented. These settings came from Race mod, which is what [N]Race based on. However, in [N]Race, these commands never have any effect.

Fun Facts:
* Race start tile resets time only when you don't have grenade weapon on hand
* By placing a "to" teleport tile without a "from" teleport tile, that "to" tile become a checkpoint for the race
