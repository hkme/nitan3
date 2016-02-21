inherit ROOM;

void create()
{
	set("short", "大驿道");
        set("long", @LONG
你走在一条尘土飞扬的大驿道上。四周人来人往。挑担子的、行商的、赶着
大车的马夫、上京赶考的书生，熙熙攘攘，非常热闹。不时还有两三骑快马从身
边飞驰而过，扬起一路尘埃。道路两旁是整整齐齐的杨树林。从这里向北向西都
可以上京城。南边通往汝州城。
LONG );
	set("exits", ([
		"north" : "/d/beijing/road3",
		"west" : "/d/beijing/road7",
		"south" : "/d/beijing/road8",
	]));
	set("objects",([
		"/d/taishan/npc/jian-ke" : 1,
	]));
 	set("outdoors", "beijing");
	set("coor/x", 60);
	set("coor/y", 250);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
