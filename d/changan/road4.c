// Room:/d/changan/road4.c

inherit  ROOM;

void  create  ()
{
	set("short",  "大官道");
	set("long",  @LONG
这是一条宽阔笔直的官道，足可容得下十马并驰。往东通向函谷关，往西则
直达长安城。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"west" :  "/d/changan/dong-chengmen",
		"east" :  "/d/changan/road3",
	]));
	set("outdoors", "changan");
	set("coor/x", -340);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
