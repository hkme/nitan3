// liuzhuang1.c

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "刘庄侧院");
        set("long", @LONG
这里是刘庄旁边的院子，你走到这里不禁有些惊奇，居然摆了几个江湖上练
武之人才用的练功木人，旁边有几个护院家丁模样的人坐在一旁指手画脚的不知
道在说些什么。
LONG );
        set("exits", ([
            "north" : "/d/hangzhou/liuzhuang",
        ]));
        set("objects", ([
                "/d/hangzhou/npc/jiading" : 2,
		"/clone/npc/mu-ren" : 3,
        ]));
        setup();
	replace_program(ROOM);
}

