// shuiledong.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "水乐洞");
        set("long", @LONG
水乐洞有两个洞口，洞的左口有股山泉从石缝中涌出。泉水声如金石，和谐
悦耳。旁有『天然琴声』，『听无弦琴』等石刻字句。洞内两壁有很多钟乳石。
往东是下山的路，西上便到了烟霞洞。
LONG );
        set("exits", ([
                "westup"    : "/d/hangzhou/yanxiadong",
                "eastdown"  : "/d/hangzhou/manjuelong",
        ]));
        set("resource/water", 1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
