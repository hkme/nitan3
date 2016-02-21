//Room: /d/dali/daduhe.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","大渡河边");
        set("long", @LONG
大渡河是蜀中名川，河谷狭窄，水流湍急，极难渡过，只有远方下游才有河
面宽阔处，可行船渡河。此处是河谷转弯的浅滩，水流稍缓，不过仍可见滔滔河
水汹涌而去，对岸可望而不可及。南边山上有座石城。
LONG );
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "southup"  : "/d/dali/wunong",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

