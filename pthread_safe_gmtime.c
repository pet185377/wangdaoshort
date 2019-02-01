#include <func.h>
void *threadfunc(void *p)
{
	time_t t=time(NULL);
	struct tm  ptime;
	memset(&ptime,0,sizeof(struct tm));
	gmtime_r(&t,&ptime);
	printf("%04d-%02d-%02d %02d:%02d:%02d %d %d\n",ptime.tm_year+1900,ptime.tm_mon+1,ptime.tm_mday,ptime.tm_hour+8,\
			ptime.tm_min,ptime.tm_sec,ptime.tm_wday,ptime.tm_yday);
	sleep(5);
	printf("%04d-%02d-%02d %02d:%02d:%02d %d %d\n",ptime.tm_year+1900,ptime.tm_mon+1,ptime.tm_mday,ptime.tm_hour+8,\
			ptime.tm_min,ptime.tm_sec,ptime.tm_wday,ptime.tm_yday);
}
int main()
{
	pthread_t pthid;
	pthread_create(&pthid,NULL,threadfunc,NULL);
	sleep(2);
	time_t t=time(NULL);
	struct tm mtime;
	memset(&mtime,0,sizeof(struct tm));
	gmtime_r(&t,&mtime);
	printf("%04d-%02d-%02d %02d:%02d:%02d %d %d\n",mtime.tm_year+1900,mtime.tm_mon+1,mtime.tm_mday,mtime.tm_hour+8,\
			mtime.tm_min,mtime.tm_sec,mtime.tm_wday,mtime.tm_yday);
	pthread_join(pthid,NULL);
	return 0;
}
