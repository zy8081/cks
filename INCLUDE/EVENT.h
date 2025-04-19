#ifndef EVENT_H
#define EVENT_H


void eventsc(int (*events)[2]);
void eventshow(int events[2],struct GameInfo* pGameInfo);
void event_scb(struct GameInfo* pGameInfo);
void event_yj(struct GameInfo* pGameInfo);
void event_dz(struct GameInfo* pGameInfo);
void event_yq(struct GameInfo* pGameInfo);
void event_sbgz(struct GameInfo* pGameInfo);
void event_yz(struct GameInfo* pGameInfo);
void event_rocket(struct GameInfo* pgameinfo);
int prt_warning(int re,int t,int ret);
int judge_warning(long int  it,long int i);
void event_warning(struct GameInfo* pgameinfo);

#endif


