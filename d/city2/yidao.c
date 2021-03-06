inherit ROOM;
#include <ansi.h>;

void create()
{
        set("short", "城外驿道");
        set("long", 
"这里是通往襄阳守军军营的驿道，由于连年来战火不止，显得格外
地荒凉，不时有来往的马匹飞奔而过，溅起一土尘烟，沿途不时有土匪
大盗出现，还是少作停留的好。\n"
);
        set("outdoors", "xiangyang");
        set("no_magic",1);

        set("exits", ([
                "east"  : __DIR__"yidao", 
                "west"  : __DIR__"yidao",
        ]));

        setup();
}

void init()
{
        object me=this_player();

        if (! me->is_busy())
        me->start_busy(random(2));


        if (me->query_temp("yidao/mark_steps") > 11)
        {
         me->move("/d/xiangyang/eastgate2");
         me->delete_temp("yidao");
         tell_object(me,YEL"一路风尘仆仆之后，襄阳已经近在眼前了......\n"NOR);
         return;
        } 

        if (me->query_temp("yidao/mark_steps") < -11)
        {
         me->move(__DIR__"syuanmen2");
         me->delete_temp("yidao");
         tell_object(me,YEL"一路风尘仆仆之后，大宋军营已经近在眼前了......\n"NOR); 
         return;
        }

        tell_object(me,YEL"你快马加鞭，一路飞驰在驿道上......\n"NOR);

}

int valid_leave(object me,string dir)
{
        object dadao,*env;
        int i,flag;
  
        env=all_inventory(environment(me));   
        flag=0;

        for(i=0;i<sizeof(env);i++)
        {
         if(objectp(env[i]) && env[i]->query("id")=="jiangyang dadao"
            && env[i]->query("killer")==me->query("id") )
         flag=1;
        }

        if ( me->query_temp("warquest/purchase") && random(12)>10 )
        {
                dadao=new("/d/city2/npc/dadao");
                dadao->set_from_me(me);
                dadao->set_temp("warquest/party","meng");
                dadao->move(environment(me));
                dadao->kill_ob(me);
                me->kill_ob(dadao);
        return notify_fail("忽然从路边丛林中杀出一路人马！\n");
        } else
        if(flag)
        return notify_fail("江阳大盗挡住了你的去路。\n");

       if( dir == "east" )
       me->add_temp("yidao/mark_steps",-random(2));
       if(  dir == "west" )
       me->add_temp("yidao/mark_steps",random(2));
       return ::valid_leave(me,dir);
}

