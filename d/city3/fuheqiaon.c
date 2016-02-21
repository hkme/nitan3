// Room: fuheqiaon.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short","府河桥");
        set("long", @LONG
这里是成都北门外府河桥。成都虽是川中首府，却无险可守，一旦敌方兵至
成都平原，即使府南两河水涨，也就只有祷告对方慈悲的选择了。
LONG );
	set("outdoors", "chengdu");
	set("exits",([ /* sizeof() == 1 */
            "north"  : "/d/qingcheng/qcroad1",
            "south"  : "/d/city3/northgate",
	]));
	set("no_clean_up", 0);
	set("coor/x", -430);
	set("coor/y", -140);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

