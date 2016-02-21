/*  <SecCrypt CPL V3R05>  */
 
//  whohave.c
// Smallfish@Huaxia

inherit  F_CLEAN_UP;

void  listing  (object  who,  string  prefix,  string  arg)
{
	object  *ilist;
	int  j;

	if  (!  present  (arg,who))
		return;
     write  (prefix+who->query("name")+"("+who->query("id")+"):");
	ilist  =  all_inventory(who);
	if  (!  ilist)
	      	return;
	j  =  sizeof(ilist);
	while  (j--)  {
		object  ob  =  ilist[j];
		string  *ids  =  ob->parse_command_id_list();
		if  (member_array(arg,  ids)  ==  -1)  {
			continue;
		}	
		write  ("  "+ob->short());
	}
	write  ("\n");
	j  =  sizeof(ilist);
	while  (j--)  {
		object  ob  =  ilist[j];
		listing  (ob,  "    "+prefix,arg);
	}
}

mixed  main(object  me,  string  arg,  int  remote)
{
	object  *ulist;
	int  i;

        if (! SECURITY_D->valid_grant(me, "(arch)"))
                return 0;

	if  (!  arg)
		return  notify_fail  ("ָ���ʽ  whohave  <id>\n");

	ulist  =  users();
	i  =  sizeof(ulist);
	while  (i--)  {
		listing  (ulist[i],  "    ",  arg);
	}
	return  1;
}

int  help  (object  me)
{
                write(@HELP
ָ���ʽ  :  whohave  <id>
  
���г�ĿǰЯ��ĳ����Ʒ����ҡ�
  
  
HELP
);
                return  1;
}