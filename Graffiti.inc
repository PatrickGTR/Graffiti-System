/*
                                        Graffiti System by Tavi (2012)
                                   	Edited by pds2k12 a.k.a Patrick_ (2014)
                                    =======================================

               
Functions
================================================================================
               
native CreateGraffiti(playerid, Float:gX, Float:gy, Float:gZ, Float:gA, gText[], gFont[], gSize, gBold, gColor[]);
native DeleteGraffiti(graffid);
native IsPlayerNearAnyGraffiti(playerid, Float:Distance);
native IsPlayerNearGraffiti(graffitiid, playerid, Float:Distance);
 
================================================================================
 
*/
 
#include <a_samp>

#define MAX_GRAFFS 100
 
enum t_GraffSystem
{
    t_gObject,
    Float:t_gX,
    Float:t_gY,
    Float:t_gZ,
};
new Graff[MAX_GRAFFS][t_GraffSystem];
new t_gCurrent[MAX_PLAYERS];
 
stock CreateGraffiti(playerid, Float:gX, Float:gY, Float:gZ, Float:gA, gText[], gFont[], gSize, gBold, gColor[])
{
    new t_gID = EmptyGraff();

    if(t_gID == -1) 
		return print("MAX_GRAFFS too small");
    
    Graff[t_gID][t_gObject] = CreateObject(19353, gX, gY, gZ, 0.0, 0.0, gA-90.0);
  
    SetObjectMaterialText(Graff[t_gID][t_gObject], gText, 0, OBJECT_MATERIAL_SIZE_256x128,\
    gFont, gSize, gBold, HexToInt(gColor), 0x00000000, OBJECT_MATERIAL_TEXT_ALIGN_CENTER);
    
    Graff[t_gID][t_gX] = gX;
    Graff[t_gID][t_gY] = gY;
    Graff[t_gID][t_gZ] = gZ;
    t_gCurrent[playerid] = t_gID;
    EditObject(playerid, Graff[t_gID][t_gObject]);
    return t_gID;
}
 
stock DeleteGraffiti(graffid)
{
    DestroyObject(Graff[graffid][t_gObject]);
    Graff[t_gObject] = 0;
    Graff[t_gX] = 0;
    Graff[t_gY] = 0;
    Graff[t_gZ] = 0;
}

stock IsPlayerNearAnyGraffiti(playerid, Float:Distance)
{
	new 
		i = -1;
	while(++i != MAX_GRAFFS)
	{
		if( IsPlayerInRangeOfPoint( playerid, Distance, Graff[i][t_gX], Graff[i][t_gY], Graff[i][t_gZ] ) )
		{
			return true;
		}
	}
	return false;
}

stock IsPlayerNearGraffiti(graffid, playerid, Float:Distance)
{
	if( IsPlayerInRangeOfPoint( playerid, Distance, Graff[graffid][t_gX], Graff[graffid][t_gY], Graff[graffid][t_gZ] ) )
	{
		return true;
	}
	return false;
}

 
stock EmptyGraff()
{
    for(new i = 0; i != MAX_GRAFFS; i++)
    {
        if(Graff[i][t_gObject] == 0)
        {
        	return i;
        }
    }
    return -1;
}
 
public OnPlayerEditObject(playerid, playerobject, objectid, response, Float:fX, Float:fY, Float:fZ, Float:fRotX, Float:fRotY, Float:fRotZ)
{
    if(response == EDIT_RESPONSE_FINAL)
    {
        new g = t_gCurrent[playerid];
        MoveObject(objectid, fX, fY, fZ, 10.0, fRotX, fRotY, fRotZ);
        Graff[g][t_gX] = fX;
        Graff[g][t_gY] = fY;
        Graff[g][t_gZ] = fZ;
    }

    #if defined t_gOnPlayerEditObject
    	t_gOnPlayerEditObject(playerid, playerobject, objectid, response, Float:fX, Float:fY, Float:fZ, Float:fRotX, Float:fRotY, Float:fRotZ);
    #endif
    return true;
}
 
#if defined _ALS_OnPlayerEditObject
    #undef OnPlayerEditObject
#else
    #define _ALS_OnPlayerEditObject
#endif
 
#define OnPlayerEditObject t_gOnPlayerEditObject
 
#if defined t_gOnPlayerEditObject
	forward t_gOnPlayerEditObject(playerid, playerobject, objectid, response, Float:fX, Float:fY, Float:fZ, Float:fRotX, Float:fRotY, Float:fRotZ);
#endif
