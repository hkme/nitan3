// Room: /d/xiangyang/eastroad2.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "东内大街");
        set("long", @LONG
这是一条青石铺就的大街。西面是一堵盖着红色琉璃瓦的高墙，里面是襄阳
守城大将王坚的府邸大院。东面是忠烈祠，因为十余年来，为保卫襄阳、抵抗蒙
古军的侵略而牺牲的人特别多，前往上香祭奠的人络绎不绝。北面是一个十字街
道，只见人来人往，非常热闹，南面是用青石铺的街道。
LONG );
        set("outdoors", "xiangyang");

	set("no_clean_up", 0);
	set("exits", ([
		"east"  : "/d/xiangyang/zhonglie",
		"south" : "/d/xiangyang/eastroad1",
		"north" : "/d/xiangyang/jiekou2",
	]));
	set("coor/x", -270);
	set("coor/y", -70);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

