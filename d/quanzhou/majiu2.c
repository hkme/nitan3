#include <room.h>
inherit TRANS_ROOM;

void create()
{
      set("short","����");
      set("long",@LONG
���Ǽ��˳ǵ����ǣ����깩Ӧ���ʲ��ϡ����������µ���ľ���϶���
һ����ľ��(paizi)��
    �����жѷ������Ѳ��ϣ�������һ����ۡ�
LONG);
      set("outdoors", "jiaxing");
      set("no_fight", 1);
      set("objects", ([
                "/clone/horse/zaohongma": 1,
                "/clone/horse/huangbiaoma": 1,
                "/clone/horse/ziliuma": 1,
                "/clone/npc/mafu": 1,
      ]));
      set("exits",([ /* sizeof() == 1 */
                "northeast" : __DIR__"jxnanmen",
      ]));
      set("coor/x", 70);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
      replace_program(TRANS_ROOM);
}
