//Room: /d/dali/milin.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","密林");
        set("long", @LONG
此处山道狭窄，林木特别茂密，山民踏出来的小道被纵横交错的林木遮挡阻
碍着，行路者不停地用刀劈砍开路，才能顺利前进。四面青山峭立，丛林中时常
有鸟兽惊走，偶尔还能看见美丽的孔雀飞过。
LONG );
	set("objects", ([
	   "/clone/beast/qingshe": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "northeast"  : "/d/dali/yangzong",
	    "southup"    : "/d/dali/shanjian",
	]));
	setup();
	replace_program(ROOM);
}

