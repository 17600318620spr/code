#include <stdio.h>
#include <string.h>


typedef struct SoftVersion_s
{
    int Major;
    int Minjor;
    int Revision;
    char GIT_Number[32];
    char BuildTime[50];
}SoftVersion_t;


int Utils_GetSoftVersion(const char *path,SoftVersion_t *version)
{

    /**************version file format******
     
        #ifndef _VERSION_H_
        #define _VERSION_H_
        #define MAJOR_VERSION 2
        #define MINOR_VERSION 0
        #define REVISION_VERSION 1
    //    #define SVN_VERSION 103
        #define DATE_VERSION 201801101430
        #endif

    *****************************************/

    if(0!=access(path,0|4))
    {
        return -1;
    }
    char buffer[2048]={'\0'};
    FILE *fp=fopen(path,"r");
    int readCount=fread(buffer,1,sizeof(buffer),fp);
    fclose(fp);
    if(readCount>2048)
    {
        return -1;
    }
    char tempStr[128]={'\0'};
    char *pBegin=NULL;
    char *pEnd=NULL;
    pBegin=strstr(buffer,"MAJOR_VERSION");                
    pEnd=strstr(pBegin,"\n");
    if(NULL!=pBegin&&NULL!=pEnd)
    {
        memcpy(tempStr,pBegin,pEnd-pBegin);  
        char *pch=strtok(tempStr," ");
        if (NULL != pch)
        {
            pch = strtok(NULL, " ");
            if(NULL != pch)
            {
                version->Major = atoi(pch);
            }
            else
            {
                version->Major=0;
            }            
        }
        else
        {
            version->Major=0;
        }
    }
    else
    {
        return -1;
    }
    pBegin=strstr(buffer,"MINOR_VERSION");                
    pEnd=strstr(pBegin,"\n");
    if(NULL!=pBegin&&NULL!=pEnd)
    {
        memcpy(tempStr,pBegin,pEnd-pBegin);  
        char *pch=strtok(tempStr," ");
        if (NULL != pch)
        {
            pch = strtok(NULL, " ");
            if(NULL != pch)
            {
                version->Minjor = atoi(pch);
            }
            else
            {
                version->Minjor = 0;
            }            
        }
        else
        {
            version->Minjor=0;
        }
    }
    else
    {
        return -1;
    }
    pBegin=strstr(buffer,"REVISION_VERSION");                
    pEnd=strstr(pBegin,"\n");
    if(NULL!=pBegin&&NULL!=pEnd)
    {
        memcpy(tempStr,pBegin,pEnd-pBegin);  
        char *pch=strtok(tempStr," ");
        if (NULL != pch)
        {
            pch = strtok(NULL, " ");
            if(NULL != pch)
            {
                version->Revision = atoi(pch);
            }
            else
            {
                version->Revision = 0;
            }
            
        }
        else
        {
            version->Revision=0;
        }
    }
    else
    {
        return -1;
    }
    pBegin=strstr(buffer,"GIT_VERSION");                
    pEnd=strstr(pBegin,"\n");
    if(NULL!=pBegin&&NULL!=pEnd)
    {
        memcpy(tempStr,pBegin,pEnd-pBegin);  
        char *pch=strtok(tempStr," ");
        if (NULL != pch)
        {
            pch = strtok(NULL, " ");
            if(NULL != pch)
            {
//              memcpy(version->GIT_Number, pch, sizeof(version->GIT_Number));
                strcpy(version->GIT_Number, pch);
		printf("fun(11111)....%s\n", version->GIT_Number);
            }
            else
            {
//              memcpy(version->GIT_Number, "0", sizeof(version->GIT_Number));
                strcpy(version->GIT_Number, "0");
		printf("fun(22222).....%s\n", version->GIT_Number);
            }            
        }
        else
        {
//        	memcpy(version->GIT_Number, "0", sizeof(version->GIT_Number));
		strcpy(version->GIT_Number, "0");
		printf("fun(33333).....%s\n", version->GIT_Number);
        }
    }
    else
    {
        return -1;
    }
    pBegin=strstr(buffer,"DATE_VERSION");                
    pEnd=strstr(pBegin,"\n");
    if(NULL!=pBegin&&NULL!=pEnd)
    {
        memcpy(tempStr,pBegin,pEnd-pBegin);  
        char *pch=strtok(tempStr," ");
        if (NULL != pch)
        {            
            pch = strtok(NULL, " ");
            if(NULL != pch)
            {
                strcpy(version->BuildTime,pch);
            }
            else
            {
                strcpy(version->BuildTime,"197001010000");
            }
            
        }
        else
        {
            strcpy(version->BuildTime,"197001010000");
        }
    }
    else
    {
        return -1;
    }
    return 0;
}

int main()
{
	char *revisionFile="./version.h";
        char revisionStr[128]={'\0'};
        SoftVersion_t version;
        memset(&version,0,sizeof(SoftVersion_t));

        if(0!=Utils_GetSoftVersion(revisionFile,&version))
	{
		sprintf(revisionStr,"%s","0.0.0.0 (000000000000)");
printf("1111111111+++++++++++%s\n", revisionStr);
	}
	else
        { 
        	sprintf(revisionStr,"%d.%d.%d.(%s) (%s)", version.Major, version.Minjor, version.Revision, version.GIT_Number, version.BuildTime);                               
printf("2222222222-----------%s\n", revisionStr);
        }

	return 0;
}
