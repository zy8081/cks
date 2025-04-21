#ifndef EVENT_H
#define EVENT_H


void eventsc(int (*events)[2]);
void eventshow(int events[2],struct GameInfo* pGameInfo);
void event_scb(struct GameInfo* pGameInfo);
void scb_show();
void scb_data(struct GameInfo* pGameInfo);
void event_yj(struct GameInfo* pGameInfo);
void yz_show();
void yz_data(struct GameInfo* pGameInfo);
void event_dz(struct GameInfo* pGameInfo);
void dz_show();
void dz_data(struct GameInfo* pGameInfo);
void event_yq(struct GameInfo* pGameInfo);
void yq_show();
void yq_data(struct GameInfo* pGameInfo);
void event_sbgz(struct GameInfo* pGameInfo);
void sbgz_show();
void sbgz_data(struct GameInfo* pGameInfo);
void event_yz(struct GameInfo* pGameInfo);
void yz_show();
void yz_data(struct GameInfo* pGameInfo);
void event_rocket(struct GameInfo* pgameinfo);
void rocket_show();
void rocket_data(struct GameInfo* pGameInfo);
int prt_warning(int re,int t,int ret);
int judge_warning(long int  it,long int i);
void event_warning(struct GameInfo* pgameinfo);
int fail_judge(struct GameInfo* pg);
void event_fail(struct GameInfo *pg,WORKFILE* pw);

#endif


