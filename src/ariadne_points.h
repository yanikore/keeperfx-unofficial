/******************************************************************************/
// Free implementation of Bullfrog's Dungeon Keeper strategy game.
/******************************************************************************/
/** @file ariadne_points.h
 *     Header file for ariadne_points.c.
 * @par Purpose:
 *     ariadne_points functions.
 * @par Comment:
 *     Just a header file - #defines, typedefs, function prototypes etc.
 * @author   Tomasz Lis
 * @date     11 Mar 2010 - 22 Jun 2010
 * @par  Copying and copyrights:
 *     This program is free software; you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation; either version 2 of the License, or
 *     (at your option) any later version.
 */
/******************************************************************************/
#ifndef DK_ARIADNE_POINTS_H
#define DK_ARIADNE_POINTS_H

#include "bflib_basics.h"
#include "globals.h"

// Originally was 4500, but we're not using fwd_path from DLL which gives us 517 extra
#define POINTS_COUNT 5017

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************/
#pragma pack(1)

typedef long AridPointId;

struct Point { // sizeof = 4
  short x;
  short y;
};

/******************************************************************************/
DLLIMPORT struct Point _DK_Points[POINTS_COUNT];
#define Points _DK_Points

#pragma pack()
/******************************************************************************/
#define INVALID_POINT (&Points[0])
/******************************************************************************/
TbBool has_free_points(long n);
AridPointId point_new(void);
void point_dispose(AridPointId pt_id);
TbBool point_set(AridPointId pt_id, long x, long y);
struct Point *point_get(AridPointId pt_id);
TbBool point_is_invalid(const struct Point *pt);
TbBool point_equals(AridPointId pt_idx, long pt_x, long pt_y);
AridPointId point_set_new_or_reuse(long pt_x, long pt_y);
void triangulation_initxy_points(long startx, long starty, long endx, long endy);

/******************************************************************************/
#ifdef __cplusplus
}
#endif
#endif
