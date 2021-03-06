
inherit "/inherit/char/npc.c";
#include <ansi.h>

int get_exp_rate();
int get_level(int exp);
void  consider();   
mapping *menpai= ({
([      "family":                "少林派",
        "gender":                "男性",
        "class":                 "bonze",
        "dodge":                 "shaolin-shenfa",
        "whip":                  "riyue-bian",
        "parry":                 "riyue-bian",
        "force":                 "hunyuan-yiqi",
        "perform1":              "whip.chan",
        "weapon":                __DIR__"obj/changbian",
]),
([      "family":               "武当派",
        "class":                 "taoist",
        "dodge":                 "tiyunzong",
        "parry":                 "taiji-quan", 
        "unarmed":               "taiji-quan",
        "sword":                 "taiji-jian",
        "force":                 "taiji-shengong",
        "perform1":              "sword.lian",
        "perform2":              "unarmed.zhen",
        "weapon":                __DIR__"obj/changjian",
]),
([      "family":               "峨嵋派",
        "gender":                "女性",
        "class":                 "bonze",
        "dodge":                 "zhutian",
        "parry":                 "yanxing-dao",
        "blade":                 "yanxing-dao",
        "force":                 "linji-zhuang",
        "finger":                "tiangang-zhi",
        "strike":                "jinding-mianzhang",
        "prepare1":              "finger",
        "prepare2":              "strike",
        "perform1":              "blade.huanying",
        "perform2":              "finger.lingkong",   
        "exert1":                "longhe",
        "exert2":                "fengyun",
        "exert3":                "daxiao", 
        "weapon":                __DIR__"obj/blade",
]),
([      "family":               "丐帮",
        "gender":                "男性",
        "class":                 "fighter",
        "dodge":                 "xiaoyaoyou",
        "parry":                 "dagou-bang",
        "staff":                 "dagou-bang",
        "force":                 "huntian-qigong",
        "strike":                "xianglong-zhang",
        "prepare1":              "strike",
        "perform1":              "staff.chan",
        "perform2":              "strike.leiting",
        "perform3":              "strike.xianglong",
        "exert1":                "powerup",
        "exert2":                "shengang",
        "weapon":                __DIR__"obj/zhubang",
]),
([      "family":               "华山派",
        "gender":                "男性",
        "class":                 "fighter",
        "dodge":                 "huashan-shenfa",
        "parry":                 "dugu-jiujian",
        "sword":                 "dugu-jiujian",
        "force":                 "zixia-shengong",
        "strike":                "hunyuan-zhang",
        "cuff":                  "poyu-quan",
        "prepare1":              "strike",
        "prepare2":              "cuff",
        "perform1":              "sword.po",
        "perform2":              "sword.poqi",
        "perform3":              "sword.pozhang",
        "exert1":                "powerup",
        "weapon":                __DIR__"obj/changjian",
]),
([      "family":               "镇南王府",
        "gender":               "男性",
        "dodge":                "tiannan-bufa",
        "parry":                "duanjia-jian",
        "sword":                "duanjia-jian",
        "force":                "kurong-changong",
        "finger":               "yiyang-zhi",
        "prepare1":             "finger",
        "exert1":               "powerup",
        "perform1":             "sword.ding",
        "perform2":             "sword.tun",
        "perform3":             "finger.yizhi",
        "weapon":                __DIR__"obj/changjian",
]),
([      "family":               "天龙寺",
        "clasee":               "bonze",
        "gender":               "男性",
        "dodge":                "tiannan-bufa",
        "parry":                "liumai-shenjian",
        "force":                "kurong-changong",
        "finger":               "liumai-shenjian",
        "prepare1":             "finger",
        "exert1":               "powerup",
        "perform1":             "finger.feng",
        "perform2":             "fenger.tan",
        "perform3":             "finger.ci",
        "perform4":             "finger.liumai",
]),
([      "family":               "明教",
        "gender":               "男性",
        "dodge":                "qiankundanuoyi",
        "parry":                "qiankundanuoyi",
        "sword":                "shenghuo-ling",
        "force":                "jiuyang-force",
        "unarmed":              "jiuyang-force",
        "cuff":                 "qishang-quan",
        "prepare1":             "unarmed",
        "exert1":               "powerup",
        "perform1":             "sword.xiyanling",
        "perform2":             "cuff.sanjiao", 
        "perform3":             "cuff.hunpofeiyang", 
        "weapon":                __DIR__"obj/shenghuoling",
]),              
([      "family":               "古墓派",
        "gender":               "女性",
        "dodge":                "yunu-shenfa",
        "parry":                "yinsuo-jinling",
        "whip":                 "yinsuo-jinling",
        "force":                "yunu-xinjing",
        "unarmed":              "meinu-quanfa",
        "prepare1":             "unarmed",
        "exert1":                "powerup",
        "perform1":             "whip.dian",
        "perform2":             "whip.feng",
        "perform3":             "unarmed.duo",
        "weapon":                __DIR__"obj/changbian",
]),
([      "family":               "全真教",
        "class":                 "taoist",
        "gender":                "男性",
        "dodge":                 "qixing-huanwei",
        "parry":                 "quanzhen-jianfa",
        "unarmed":               "kongming-quan",
        "sword":                 "quanzhen-jianfa",
        "force":                 "tiangang-zhengqi",
        "finger":                "yiyang-zhi",     
        "prepare1":              "finger",  
        "perform1":              "sword.sanqing",
        "perform2":              "sword.qixing",
        "perform3":              "sword.tonggui", 
        "perform4":              "finger.yizhi",
        "weapon":                __DIR__"obj/changjian",
]),   
([      "family":                "云龙门",
        "class":                 "sworder",
        "gender":                "男性",
        "dodge":                 "yunlong-shenfa",
        "parry":                 "houquan",
        "unarmed":               "houquan",
        "sword":                 "yunlong-jian",
        "force":                 "yunlong-shengong",
        "perform1":              "sword.xian",
        "perform2":              "parry.zhen", 
        "exert1":                "powerup",
        "weapon":                __DIR__"obj/changjian",
]),  
([      "family":                "红花会",
        "class":                 "sworder",
        "gender":                "男性",
        "dodge":                 "yunlong-shenfa",
        "parry":                 "baihuacuo-quan",
        "unarmed":               "baihuacuo-quan",
        "sword":                 "luohua-jian",
        "force":                 "honghua-shengong",
        "exert1":                "powerup",
        "weapon":                __DIR__"obj/changjian",
]),
([      "family":                "浣花剑派",
        "class":                 "sworder",
        "gender":                "男性",
        "dodge":                 "feihua-wuping",
        "parry":                 "tiexian-quan",
        "unarmed":               "tiexian-quan",
        "sword":                 "huanhua-jian",
        "force":                 "guiyuan-dafa",
        "exert1":                "powerup",
        "perform1":              "sword.snow",     
        "perform2":              "sword.zhenjian",  
        "weapon":                __DIR__"obj/changjian",
]),  
});

mapping fam=([
"少林派":   0,
"武当派":   1,
"峨嵋派":   2,
"丐帮":     3,
"华山派":   4,
"镇南王府": 5,
"天龙寺":   6,
"明教":     7,
"古墓派":   8,
"全真教":   9,
"云龙门":   10,
"红花会":   11,
"浣花剑派": 12,
]);
mapping *first_name=({
([      "name":"孙",      "id":"sun"    ]),
([      "name":"吴",      "id":"wu"     ]),
([      "name":"独孤",    "id":"dugu"   ]),
([      "name":"赖",      "id":"lai"    ]),
([      "name":"林",      "id":"lin"    ]),
([      "name":"赵",      "id":"zhao"   ]),
([      "name":"任",      "id":"ren"    ]),
([      "name":"钱",      "id":"qian"   ]),
([      "name":"李",      "id":"li"     ]),
([      "name":"张",      "id":"zhang"  ]),
([      "name":"臧",      "id":"zang"   ]),
([      "name":"徐",      "id":"xu"     ]),
([      "name":"杨",      "id":"yang"   ]),
([      "name":"邱",      "id":"qiu"    ]),
([      "name":"舒",      "id":"shu"    ]),
([      "name":"叶",      "id":"ye"     ]),
([      "name":"刘",      "id":"liu"    ]),
([      "name":"周",      "id":"zhou"   ]),
([      "name":"杨",      "id":"yang"   ]),
([      "name":"王",      "id":"wang"   ]),
([      "name":"梁",      "id":"liang"  ]),
([      "name":"于",      "id":"yu"     ]),
([      "name":"黄",      "id":"huang"  ]),
([      "name":"林",      "id":"lin"    ]),
([      "name":"陈",      "id":"chen"   ]),
([      "name":"谢",      "id":"xie"    ]),
([      "name":"鲁",      "id":"lu"     ]),
([      "name":"何",      "id":"he"     ]),
([      "name":"曾",      "id":"zeng"   ]),
([      "name":"郭",      "id":"guo"    ]),
([      "name":"成",      "id":"cheng"  ]),
([      "name":"南宫",    "id":"nangong"  ]),
([      "name":"欧阳",    "id":"ouyang"   ]),
([      "name":"长孙",    "id":"zhangsun" ]),
([      "name":"慕容",    "id":"murong"   ]),
([      "name":"西门",    "id":"ximen"    ]),
([      "name":"公孙",    "id":"gongsun"  ]),
});

mapping *second_name1=({
([      "name":"",      "id":""      ]),
([      "name":"风",    "id":"feng"  ]),
([      "name":"德",    "id":"de"    ]),
([      "name":"晓",    "id":"xiao"  ]),
([      "name":"润",    "id":"run"   ]),
([      "name":"富",    "id":"fu"    ]),
([      "name":"达",    "id":"da"    ]),
([      "name":"默",    "id":"mo"    ]),
([      "name":"玄",    "id":"xuan"  ]),
([      "name":"海",    "id":"hai"   ]),
([      "name":"自",    "id":"zi"    ]),
([      "name":"泰",    "id":"tai"   ]),
([      "name":"昭",    "id":"zhao"  ]),
([      "name":"",      "id":""      ]),
([      "name":"通",    "id":"tong"  ]),
([      "name":"耘",    "id":"yun"   ]),
([      "name":"奋",    "id":"fen"   ]),
([      "name":"宏",    "id":"hong"  ]),
([      "name":"荣",    "id":"rong"  ]),
([      "name":"鹏",    "id":"peng"  ]),
([      "name":"冲",    "id":"chong" ]),
([      "name":"灏",    "id":"hao"   ]),
([      "name":"思",    "id":"si"    ]),
([      "name":"理",    "id":"li"    ]),
([      "name":"刚",    "id":"gang"  ]),
([      "name":"武",    "id":"wu"    ]),
([      "name":"逸",    "id":"yi"    ]),
});


mapping *second_name2=({
([      "name":"凤",    "id":"feng"  ]),
([      "name":"玉",    "id":"yu"    ]),
([      "name":"",      "id":""      ]),
([      "name":"子",    "id":"zi"    ]),
([      "name":"金",    "id":"jin"   ]),
([      "name":"忆",    "id":"yi"    ]),
([      "name":"淑",    "id":"shu"   ]),
([      "name":"碧",    "id":"bi"    ]),
([      "name":"兰",    "id":"lan"   ]),
([      "name":"英",    "id":"ying"  ]),
([      "name":"语",    "id":"yu"    ]),
([      "name":"嫣",    "id":"yan"   ]),
([      "name":"珠",    "id":"zhu"   ]),
([      "name":"紫",    "id":"zi"    ]),
([      "name":"霞",    "id":"xia"   ]),
([      "name":"彩",    "id":"cai"   ]),
([      "name":"丽",    "id":"li"    ]),
([      "name":"莉",    "id":"li"    ]),
([      "name":"君",    "id":"jun"   ]),
([      "name":"婉",    "id":"wan"   ]),
});

mapping *third_name1=({
([      "name":"峰",    "id":"feng"  ]),
([      "name":"华",    "id":"hua"   ]),
([      "name":"奇",    "id":"qi"    ]),
([      "name":"歌",    "id":"ge"    ]),
([      "name":"旭",    "id":"xu"    ]),
([      "name":"发",    "id":"fa"    ]),
([      "name":"威",    "id":"wei"   ]),
([      "name":"晖",    "id":"hui"   ]),
([      "name":"城",    "id":"cheng" ]),
([      "name":"轩",    "id":"xuan"  ]),
([      "name":"勇",    "id":"yong"  ]),
([      "name":"泰",    "id":"tai"   ]),
([      "name":"在",    "id":"zai"   ]),
([      "name":"君",    "id":"jun"   ]),
([      "name":"军",    "id":"jun"   ]),
([      "name":"凡",    "id":"fan"   ]),
([      "name":"伟",    "id":"wei"   ]),
([      "name":"帆",    "id":"fan"   ]),
([      "name":"雄",    "id":"xiong" ]),
([      "name":"涛",    "id":"tao"   ]),     
([      "name":"波",    "id":"bo"    ]),
([      "name":"杰",    "id":"jie"   ]),
([      "name":"郎",    "id":"lang"  ]),     
});

mapping *third_name2=({
([      "name":"兰",    "id":"lan"   ]),
([      "name":"婷",    "id":"ting"  ]),
([      "name":"霞",    "id":"xia"   ]),
([      "name":"莲",    "id":"lian"  ]),
([      "name":"卿",    "id":"qing"  ]),
([      "name":"楣",    "id":"mei"   ]),
([      "name":"妹",    "id":"mei"   ]),
([      "name":"敏",    "id":"min"   ]),
([      "name":"菲",    "id":"fei"   ]),
([      "name":"贞",    "id":"zhen"  ]),
([      "name":"君",    "id":"jun"   ]),
([      "name":"嫣",    "id":"yan"   ]),
([      "name":"凤",    "id":"feng"  ]),
([      "name":"燕",    "id":"yan"   ]),
([      "name":"珍",    "id":"zhen"  ]),
([      "name":"真",    "id":"zhen"  ]),
([      "name":"香",    "id":"xiang" ]),
([      "name":"玉",    "id":"yu"    ]),
([      "name":"娘",    "id":"niang" ]),
});

void create()
{
        string id1,id2,id3,idf1,idf2,temp1,temp2;
        string name1,name2,title;
        int i,skill,skill_lvl,basic_radio,basic_skill,index,index1,index2,nl,exp;
        mapping    mp;
        string *basic=({"dodge","unarmed","force","parry","finger","hand",
                        "strike","taoism","club","staff","fork","hammer",
                        "blade","cuff","axe","sword","whip","dagger",
                        "throwing","claw" ,"poison"});
        int ratio=100,rate;
        string *chat_chance_combat_here=({});
        object weapon;

        index1=random(sizeof(first_name));
        index2=random(sizeof(first_name));        
        name1=first_name[index1]["name"];
        name2=first_name[index2]["name"];
        id1=first_name[index1]["id"];
        id2=first_name[index2]["id"];
        idf1=id1;
        idf2=id2;
        index1=random(sizeof(second_name1));
        index2=random(sizeof(second_name2));
        name1+=second_name1[index1]["name"];
        name2+=second_name2[index2]["name"];
        id1+=" "+second_name1[index1]["id"];
        id2+=" "+second_name2[index2]["id"];


        index1=random(sizeof(third_name1));
        index2=random(sizeof(third_name2));
        name1+=third_name1[index1]["name"];
        name2+=third_name2[index2]["name"];
        id1+=third_name1[index1]["id"];
        id2+=third_name2[index2]["id"];

        set_name(name1,({id1,idf1}) );
        temp1 = read_file(__DIR__"fam1", 1, 1);
        temp2 = read_file(__DIR__"fam2", 1, 1);
        index=fam[temp1];
        mp=menpai[index];
        if (mp["gender"]) set("gender",mp["gender"]);
        if (query("gender")=="女性") set_name(name2,({id2,idf2}));
        if (mp["class"]) set("class",mp["class"]);
        if (mp["family"]) set("family/family_name",mp["family"]);
        title=HIW+mp["family"]+"同道"+NOR;
        ratio=90+random(50);

//here begin to set_skill of this_object()

        rate=get_exp_rate();
        exp=(random(rate)+1)*(random(rate)+1)*100000;  

        skill=get_level(exp);
        if(skill<50)    skill=50;

        for (i=0;i<sizeof(keys(mp));i++)
        {
                if (member_array(keys(mp)[i],basic)!=-1)
                        {
                                set_skill(keys(mp)[i],skill);
                                set_skill(mp[keys(mp)[i]],skill);
                                map_skill(keys(mp)[i],mp[keys(mp)[i]]);
                        }
        }

        if(mp["family"]=="全真教")      
          set_skill("xiantian-gong",skill);  
        if(mp["family"]=="古墓派")
          set_skill("tianluo-diwang",skill);
        if(mp["family"]=="星宿派")
          set_skill("beiming-shengong",skill);
        if(mp["class"]=="taoist")
          set_skill("taoism",skill);
        if(mp["family"]=="峨嵋派")
          set_skill("mahayana",skill);    
        if(mp["family"]=="少林派")
          set_skill("buddhism",skill);
        if(mp["family"]=="血刀门")
          set_skill("mizong-xinfa",skill);
        if(mp["family"]=="五毒教")
          set_skill("duji",skill);      
        if(mp["family"]=="明教")
          set("family/family_name","明教"); 

        if (mp["prepare1"])
           prepare_skill(mp["prepare1"],query_skill_mapped(mp["prepare1"]));
        if (mp["prepare2"])
           prepare_skill(mp["prepare2"],query_skill_mapped(mp["prepare2"]));
        set("chat_chance_combat",50);
        if (mp["perform1"])
        chat_chance_combat_here+=({(: perform_action, mp["perform1"] :)});
        if (mp["perform2"]) 
        chat_chance_combat_here+=({(: perform_action, mp["perform2"] :)}); 
        if (mp["perform3"]) 
        chat_chance_combat_here+=({(: perform_action, mp["perform3"] :)}); 
        if (mp["perform4"]) 
        chat_chance_combat_here+=({(: perform_action, mp["perform4"] :)}); 

        if (mp["exert1"])
        chat_chance_combat_here+=({(: exert_function, mp["exert1"] :)});
        if (mp["exert2"]) 
        chat_chance_combat_here+=({(: exert_function, mp["exert2"] :)});
        if (mp["exert3"]) 
        chat_chance_combat_here+=({(: exert_function, mp["exert3"] :)});
        if (mp["exert4"]) 
        chat_chance_combat_here+=({(: exert_function, mp["exert4"] :)});
        chat_chance_combat_here+=({(: exert_function, "powerup" :)});
        chat_chance_combat_here+=({(: exert_function, "recover" :)});

        set("chat_msg_combat",chat_chance_combat_here);
        set("str",(25+random(6)));
        set("con",(25+random(6)));
        set("dex",(25+random(6)));

        set("chat_chance", 5);
        set("chat_msg", ({
             (: consider :),
             (: random_move :)
        }) );
        set("is_robber",1); 
        nl=skill*10+exp/1000;
        set("max_neili",nl*ratio/10);
        set("neili",query("max_neili")*3/2);
        set("max_jingli",skill*20*ratio/10);
        set("jingli",query("max_jingli"));
        set("shen_type",1);
        basic_radio=skill/10;
        set("max_qi",(query("max_neili")*ratio/200+1000*basic_radio));
        set("qi",query("max_qi"));
        set("eff_qi",query("max_qi"));
        set("max_jing",query("max_jingli")*ratio/300+400*basic_radio);
        set("eff_jing",query("max_jing"));
        set("jiali",skill/5);      

        set("food",500);
        set("water",500);
        set("combat_exp",exp/100*ratio);
        if(exp>10000000) title+=HIR"   世外高人"NOR;
        else if(exp>8000000) title+=HIG"   江湖名宿"NOR;
        else if(exp>6000000) title+=MAG"   武林宗师"NOR;
        else if(exp>4000000) title+=HIB"   威震一方"NOR;
        else if(exp>2000000) title+=RED"   声名赫赫"NOR;
        else if(exp>1000000) title+=HIC"   当世英杰"NOR;
        else title+=HIW"   后起之秀"NOR;
        set("env/wimpy", 60);
        set("title",title);  
        setup();
        
        set_temp("chousha/fam",temp2);
        if (mp["weapon"])        
        {
         weapon=carry_object(mp["weapon"]);
         weapon->wield();
         set("weapon",weapon->query("id"));
         for(i=0;i<3;i++)
         carry_object(mp["weapon"]); 
        }   
//        carry_object(mp["weapon"])->wield();
        carry_object(__DIR__"obj/tiejia")->wear();
}


void  consider()
{
        object me=this_object();

        if(me->is_fighting() && ( query("qi")*2 < query("max_qi")
           || query("eff_qi")*3/2 < query("max_qi") ) )
         command("surrender");   

        if( !me->query_temp("weapon") )
        {
          command("grin");
          if( query("weapon") ) command("wield "+query("weapon"));
        }
        return;
}


void init()
{
        object ob,*env;
        int i;
        object killer=this_object();   


        command("yun powerup");
        ob=this_player();
        if(!killer->query_temp("chousha/fam"))
        return;

        if(this_object()->query("jiali")==0)
        set("jiali", (int)this_object()->query_skill("force")/6);

        if (random(10)>8 && ob->query_temp("chousha/fam") && userp(ob) && !ob->is_fighting()
        && ob->query_temp("chousha/fam")==killer->query_temp("chousha/fam"))
        {
        command("touch "+ob->query("id"));
        command("say "+RANK_D->query_respect(ob)
        +"，你来得正好，我们又有强援了，哈哈！\n");
        return;
        }

        env=all_inventory(environment(killer));
        for(i=0;i<sizeof(env);i++)
        {
        if (living(env[i]) && env[i]->query_temp("chousha/fam") && !userp(env[i])
            && env[i]->query_temp("chousha/fam")==killer->query("family/family_name"))
        if( killer->query("combat_exp")/2 <= env[i]->query("combat_exp")
           && killer->query("combat_exp") >= env[i]->query("combat_exp")/2)  
          {
           if(killer->query("eff_qi")>= killer->query("max_qi")*8/10
              && env[i]->query("eff_qi")>= env[i]->query("max_qi")*8/10 )           
                killer->fight_ob(env[i]); 
           else
           {
            killer->remove_all_enemy();
            killer->remove_all_killer();
           }   
          }
        }

        if (ob->query_temp("chousha/fam")
            && ob->query_temp("chousha/fam") == killer->query("family/family_name")) 
        {
        if( killer->query("combat_exp") <= ob->query("combat_exp")*5/2
           && killer->query("combat_exp") >= ob->query("combat_exp")*2/5)
        {
        message_vision(HIR"$N对$n怒喝道: “邪魔外道，看你往哪里跑，"
        +"还不速速下跪受死！\n"NOR,killer,ob);
        if(userp(ob))
        {
        killer->set_temp(ob->query("id"),1);
        killer->set_leader(ob);
        killer->kill_ob(ob); 
        ob->kill_ob(killer);
        }
        } else
        if( killer->query("combat_exp")*2/5 > ob->query("combat_exp") && random(5)>3)
        message_vision(HIC"$N对$n喝道: “杀你这种小角色怕脏了我的手，"
        +"还不快给我滚！\n"NOR,killer,ob); 
        else
        if(killer->query("combat_exp")<ob->query("combat_exp")*2/5 && random(5)>3)
        message_vision(HIW"$N对$n大义凛然道: “撞到阁下手里我也认了，"
        +"要杀要剐悉听尊便！\n"NOR,killer,ob);
        } else
        {
                add_action("do_kill","team kill");
                add_action("do_kill","kill");
                add_action("do_kill","hit");
                add_action("do_kill","fight");
                add_action("do_kill","touxi");   
                add_action("do_kill","steal");
                add_action("do_kill","beg");
                add_action("do_kill","persuade");
        }
}

void start_escape(int time)
{
        call_out("escape_me",time);
}

int do_kill(string arg)
{
        string what,who;
        if(!arg) return 0;
        if(this_object()->id(arg))
        {
                write("江湖仇杀是非多，还是少惹为妙。\n");
                return 1;
        }
        else
        if(sscanf(arg,"%s from %s",what,who)==2 && this_object()->id(who))
        {
                write("还是到别处去施展你的本事吧。\n");
                return 1;
        }
        return 0;
}

void escape_me()
{
        object ob=this_object(); 
        message_vision(
        HIW"$N大笑了几声：“今天痛痛快快地砍了这帮江湖宵小们一顿，\n"+
        "总算没有辜负掌门的重托了，哈哈哈哈！”\n说罢，一个筋斗跳出战圈，不知去向。\n"NOR,ob);
        remove_call_out("escape_me");
        destruct(ob);
}

int get_level(int exp)
{
  int level=0;
  do {
      level++;
     } while(level*level*level<(exp*10));

  return level;    
}               

void unconcious()
{
        this_object()->die();
}

void die()
{
        int reward_exp,reward_pot,reward_score;
        object killer,me;
        int team_num,team_exp,team_pot,n;
        object *team;

        me=this_object();
        killer=me->query_temp("last_damage_from");
        message_vision(HIC"$N惨嚎一声，口喷鲜血，到在地上死了。\n"NOR,me);
        
        if(killer && userp(killer) 
        && killer->query_temp("chousha/fam")==me->query("family/family_name"))
        {
         reward_exp=me->query("combat_exp")/600;

         if(killer->query("combat_exp") > me->query("combat_exp")*2)
           reward_exp=reward_exp/2;
         if(killer->query("combat_exp") < me->query("combat_exp")/2)
           reward_exp=reward_exp*4/3;
         if(reward_exp > 20000) reward_exp=20000;
         if( !me->query_temp(killer->query("id")))
         {
         tell_object(killer,HIW"可惜，你杀的人不是你该杀的！\n"NOR);
         reward_exp=reward_exp/10;
         }
         reward_exp=reward_exp/2+random(reward_exp/2);
         reward_pot=reward_exp/3+random(50)+50-killer->query_int()/5;
         reward_score=reward_exp/50;
         if (reward_pot<0) reward_pot=0;


        if(pointerp(team=killer->query_team()))
        {
         team_num=sizeof(team);
         team_exp=reward_exp/(team_num+1);
         team_pot=reward_pot/(team_num+1);
         for(n=0;n<team_num;n++)
         {
         if( team[n] != killer && objectp(team[n]) && environment(team[n]) )
         if( team[n]->query_temp("chousha/fam")
             && team[n]->query_temp("chousha/fam") == killer->query_temp("chousha/fam")
             && team[n]->is_killing(me) )   
          {
           tell_object(team[n],HIW"你所参加的队伍奖励你奋勇杀敌之战功——"
           +"你获得了"+CHINESE_D->chinese_number(team_exp)+"点实战经验和\n"
           +CHINESE_D->chinese_number(team_pot)+"点潜能奖励！\n"NOR);

                   team[n]->add("chousha_quest/reward_exp",team_exp);
                   team[n]->add("chousha_quest/reward_potential",team_pot);
                   team[n]->add("combat_exp",team_exp);
                   team[n]->add("potential",team_pot);
                   team[n]->add_temp("chousha/reward_exp",team_exp); 
           }
          }
          reward_exp=team_exp*2;
          reward_pot=team_pot*2;
         }

                   tell_object(killer,HIW"在实战中，你获得了"+
CHINESE_D->chinese_number(reward_exp) +"点的『实战经验』"+
CHINESE_D->chinese_number(reward_pot)+"点的『潜能』\n"
+"及"+CHINESE_D->chinese_number(reward_score)+"点综合评价奖励！\n"NOR); 
                   killer->add("chousha_quest/reward_exp",reward_exp);
                   killer->add("chousha_quest/reward_potential",reward_pot);
                   killer->add("chousha_quest/reward_score",reward_score);
                   killer->add("combat_exp",reward_exp);
                   killer->add("potential",reward_pot);
                   killer->add("score",reward_score);
                   killer->add_temp("chousha/reward_exp",reward_exp);

message("channel:rumor",HIB"【江湖仇杀】"NOR+HIR+killer->query("name")+NOR
+HIB"杀死了"NOR+HIR+me->query("name")+NOR+HIB"，获得了"
+CHINESE_D->chinese_number(reward_exp)
+"点实战经验、"+CHINESE_D->chinese_number(reward_pot)+"点潜能\n"
+"及"+CHINESE_D->chinese_number(reward_score)+"点综合评价奖励！\n"NOR,
users());
                  if(killer->query_temp("chousha/reward_exp")>200000)
                  {
message("channel:rumor",HIB"【江湖仇杀】"NOR+HIR+killer->query("name")+NOR
+HIB"在此次仇杀中已获得超过二十万点经验，自动退出此次江湖仇杀！\n"NOR,users());
                  killer->delete_temp("chousha");
                  }
                }

        remove_call_out("escape_me");
        destruct(me);
        return;
}

/*
int get_exp_rate()
{
     object *ulist;
     int i,max_exp=1000000,exp_rate=6;

     ulist  =  users();
     i = sizeof(ulist);
     while (i-- )
     {
         if ( !environment(ulist[i]) ) continue;
         if ( wizardp(ulist[i]) ) continue;  

         if ((int)ulist[i]->query("combat_exp") > max_exp)
         max_exp=(int)ulist[i]->query("combat_exp");
     }

     do{
         exp_rate++;
       } while(exp_rate*exp_rate<max_exp/100000);
    
     return (exp_rate*8/5);
}

*/

int get_exp_rate()
{
        string temp;
        int exp_rate;

        temp=read_file(__DIR__"exp_rate",1,1);
        exp_rate=atoi(temp);
        if( exp_rate < 6 ) exp_rate=6;
        return exp_rate;
}
