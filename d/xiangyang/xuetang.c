// Room: /d/xiangyang/xuetang.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "学堂");
        set("long", @LONG
这里是襄阳的学堂，窗明几净，一尘不染。一位庄重严肃的老先生坐在太师
椅上讲学。在他的两侧坐满了求学的学生。一张古意盎然的书案放在老先生的前
面，案上摆着几本翻开了的线装书籍。
LONG );
	set("exits", ([
		"west" : "/d/xiangyang/southjie1",
	]));
	set("objects", ([
		"/d/xiangyang/npc/laoxiansheng" : 1,
	]));
	set("coor/x", -280);
	set("coor/y", -100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
