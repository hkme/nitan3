// shijie1.c

inherit ROOM;

void create()
{
        set("short", "石阶");
        set("long", @LONG
山路突然陡峭，两旁山峰笔立，中间留出一条窄窄的石阶，仅能两人并肩而
行。
LONG );
        set("outdoors", "heimuya");
        set("exits", ([
            "eastdown" : "/d/heimuya/shandao2",
            "westup"   : "/d/heimuya/shijie2",
        ]));
        set("objects", ([
            CLASS_D("riyue") + "/fansong": 1,
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
