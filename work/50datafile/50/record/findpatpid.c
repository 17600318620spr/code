#include <stdio.h>

unsigned short Find_PAT(char * srcfile)//从PAT表中找出PMT表的PID
{
	FILE *fpr;
	int size=0;
	int ret;
	unsigned short PID;//TS包头PID
	unsigned short PMT_PID;//PMT表的PID
	unsigned short program_number;//节目号
	unsigned char adaptation_field_control;//自适应字段标志
	unsigned char *p;
	unsigned char *pat;//指向PAT表的指针
	unsigned char *p_program_num;//指向节目号的指针
	unsigned short pat_section_length;
	fpr=fopen(srcfile,"rb");
	if(NULL==fpr)return 0;
	while(!feof(fpr))
	{
		unsigned char *m_buf;
		ret=fread(m_buf+size,1,sizeof(m_buf)-size,fpr);
		size+=ret;
		p=m_buf;
		while(p+188<m_buf+size)
		{
			if((0x47==p[0])&&(0x47==p[188]))
			{
				PID=(p[1]&0x1f)<<8|p[2];
				if(0==PID)
				{
					adaptation_field_control=(p[3]>>4)&0x3;
					switch(adaptation_field_control)
					{
						case 0:
						case 2:
							p+=188;
							continue;
					        case 1:
							pat=p+4+1+p[4];
							break;
					        case 3:
							pat=p+5+p[4]+1+p[5+p[4]];
							break;
					}
					p_program_num=pat+8;
					pat_section_length=(pat[1]&0xf)<<8|pat[2];
					program_number=(p_program_num[0]<<8)|p_program_num[1];
					while(p_program_num+4<pat+3+pat_section_length)
					{
						if(0x0==program_number)
						{
							p_program_num+=4;
							program_number=(p_program_num[0]<<8)|p_program_num[1];
						}
						else 
						{
							PMT_PID=(p_program_num[2]&0x1f)<<8|p_program_num[3];
							fclose(fpr);
							return PMT_PID;
						}
					}
					p+=188;
				}else{p+=188;}
			}else{p++;}
		}
		size=m_buf+size-p;
		memmove(m_buf,p,size);
	}
	fclose(fpr);
	return 0;
}

int main()
{
	Find_PAT("test0.ts");
	return 0;
}
