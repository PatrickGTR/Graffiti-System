## Introduction ##
- Graffiti system is usually used on Roleplay servers, a gang member tags a wall to represent their Gang or to vandalize another gang's tag to cause gang-war.

## Credits ##
- [Yvax](http://forum.sa-mp.com/member.php?u=98567): Original created of this include.
- [Patrick_](http://forum.sa-mp.com/member.php?u=178953): Updated the include to [Hook Method 7](http://forum.sa-mp.com/showthread.php?t=441293) and added <b>IsPlayerNearAnyGraffiti</b> and <b>IsPlayerNearGraffiti</b> function.


## Natives ##
- native CreateGraffiti(playerid, Float:gX, Float:gy, Float:gZ, Float:gA, gText[], gFont[], gSize, gBold, gColor[]);
- native DeleteGraffiti(graffid);
- native IsPlayerNearAnyGraffiti(playerid, Float:Distance);
- native IsPlayerNearGraffiti(graffitiid, playerid, Float:Distance);
