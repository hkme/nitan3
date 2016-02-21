// room: /d/baituo/barn
// Jay 10/8/96

inherit ROOM;

void create()
{
	set("short", "����");
        set("long", @LONG
����ŷ�����ҵ����ᣬ���ﵽ�����Ƕ��ߣ�ǽ����һ�š��߾���(shejing)��
�������һ�Ѳ����õ���¨(zhulou)��
LONG );
	set("exits", ([ 
                "north" : __DIR__"road2",
		"south" : __DIR__"road1",
	]));
	set("item_desc", ([
		"shejing" : 
		"ŷ������ѵ���ܷ�����Ԧ�����ﵽ��ʮ�����ϣ��ɳ��Խ����߱�(bian)�����ȣ�\n"
		"��������ŷ�����ҵĶ��ű�����Ҳ���԰����ȱ�ض��ߣ���ʹ���ˡ�\n",
		"zhulou" : "һ�Ѳ����õ���¨��ŷ�����ҵ�����Ҫ����ʱ��������������(take)��\n",
	]));
	set("objects", ([ 
                __DIR__"npc/snake" : 3,
	 ]) );

	setup();
}


void init()
{
	add_action("do_lingwu","lingwu");
	add_action("do_take","take");
}

int do_lingwu(string arg)
{
	object me = this_player();
	int level, check;

	level = (int)me->query_skill("poison",1);
	check = level*level*level;

	if (!arg || arg!="shejing") 
		return notify_fail("��Ҫ����ʲô��\n");
	
	if (!me->query("family") || me->query("family/family_name") != "ŷ������")
		return notify_fail("����δ����գ���������߾���\n");

	if ( level < 30) 
		return notify_fail("�������Զ�����ڸ�����޷�����\n");

	if ( level > 100) 
		return notify_fail("�������Զ���̫ǳ��û���κΰ�����\n");

	if ( check > (int)me->query("combat_exp")*10 )
		return notify_fail("��ʵս���鲻�㣬�޷�����\n");

	if ( (int)me->query("jing") < 30 )
		return notify_fail("�㾫���޷����С�\n");

	me->receive_damage("jing", 20);
	me->improve_skill("poison", me->query("int"));
	write("�������߾���������ʩ���ķ��š�\n");
	return 1;
}

int do_take(string arg)
{
	object me = this_player(), obj, fire;

      if( me->query("family/family_name") != "ŷ������" ) return notify_fail("�㲻��ŷ�����ҵ�����ʲô��\n");

	if (!arg && arg != "zhulou" && arg != "basket" ) 
		return notify_fail("��Ҫ��ʲ�᣿\n");

        if (time() - me->query_temp("zhulou_last_taked") < 180) 
            return notify_fail("���Ѿ��ù�����¨�ˣ��Ȼ������ðɡ�\n");

	obj = new(__DIR__"obj/zhulou");
	obj->move(me);
	obj->set("keeper", me->query("id"));
	obj->set("long", 
	        "һ��������ɵ�¨�ӣ���ŷ�����ҵ���ר��������(catch)�ߵġ�\n"
	        "¨���������һ��СֽƬ������д�šu"+me->name()+"�v��\n"
	);
	message_vision("$N����������ҳ���һ����¨��\n", me );
        me->set_temp("zhulou_last_taked", time()); 
	fire = new("/d/xingxiu/obj/fire");
	fire->move(obj);

	return 1;
}