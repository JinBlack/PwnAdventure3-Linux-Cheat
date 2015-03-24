#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>
#include <string.h>

unsigned char superman = 1;
float walkingSpeed = 1500.0;
float jumpSpeed = 1500.0;
unsigned char sanjiJump = 1;
FILE *standardin = 0;

float _ZN6Player15GetWalkingSpeedEv(void* pThis){
    if (superman == 0){
        float (*original)(void*);
        original = dlsym(RTLD_NEXT,"_ZN6Player15GetWalkingSpeedEv");
        return (*original)(pThis);
    }
	return walkingSpeed;
}

float  _ZN6Player12GetJumpSpeedEv(void* pThis){
    if (superman == 0){
        float (*original)(void*);
        original = dlsym(RTLD_NEXT,"_ZN6Player12GetJumpSpeedEv");
        return (*original)(pThis);
    }
    return jumpSpeed;
}

// int _ZN6Player7GetManaEv(void){
//     return 100;
// }

int _ZN16GreatBallsOfFire11CanActivateEP7IPlayer(){
    return 1;
}

int _ZN8ZeroCool11CanActivateEP7IPlayer(){
    return 1;
}

int _ZN10Projectile15GetSplashDamageEv(void){
    return 100;
}

int  _ZN10Projectile15HasSplashDamageEv(void){
    return 1;
}

int _ZN10Projectile15GetSplashRadiusEv(void){
    return 100;
}

int _ZN21FastTravelDestination11IsAvailableEP6Player(){
    return 1;
}

int _ZNK6Player7IsAdminEv(void){
    return 1;
}

int _ZN9BearChest12IsArmedStageEv(void){
    return 0;
}

int _ZN9BearChest12IsEliteStageEv(void){
    return 0;
}


int _ZN6Player7CanJumpEv(void){
    return 1;
}

int _ZN6Player12CanBeDamagedEP6IActor(void *IActor){
    return 0;
}

void _ZN6Player4ChatEPKc (void *pThis, char *str){
    const char delim[2] = " ";
    void (*original)(void*, char *);
    original = dlsym(RTLD_NEXT,"_ZN6Player4ChatEPKc");
    char *token;

    if (str && str[0] == '!'){

        token = strtok(str, delim);
        if (!token){
            printf("Error\n");
            return;
        }

        printf("%sAAA\n", token);

        if (strcmp("!superman", token) == 0){
            superman = 1;
            printf("You are superman now\n");       
        }
        else if (strcmp("!speedWSet", token) == 0){
            token = strtok(NULL, delim);
            if (token){
                sscanf(token, "%f", &walkingSpeed);
                printf("You speed is %f\n", walkingSpeed);       
            }
        }
        else if (strcmp("!speedJSet", token) == 0){
            token = strtok(NULL, delim);
            if (token){
                sscanf(token, "%f", &jumpSpeed);
                printf("You speed is %f\n", jumpSpeed);       
            }
        }
        else if (strcmp("!disable", token) == 0){
            superman = 0;
            printf("You are loser now\n");       
        }


        printf("%s\n", str);
    }
    else{
        (*original)(pThis, str);
    }
}

void _ZN7GameAPI4TickEf(void* pThis, float deltat){
        void *(*original)(void*, float);
        original = dlsym(RTLD_NEXT,"_ZN7GameAPI4TickEf");
        
//        printf("Hook! %f\n",deltat);

        (*original)(pThis, deltat);
}
