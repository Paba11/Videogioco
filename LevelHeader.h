//
// Created by Paolo Sbarzagli on 25/02/23.
//

#ifndef VIDEOGIOCO_LEVELHEADER_H
#define VIDEOGIOCO_LEVELHEADER_H

#define FIRST_TABLE_ARRIVAL 5.f;

#define LEVEL_ONE_ARRIVALS 5.f;   //FIXME change arrival time
#define LEVEL_ONE_DIFFICULTY 1.f;
#define LEVEL_ONE_TOT_CUSTOMERS 30.f;

#define LEVEL_TWO_ARRIVALS 80.f;
#define LEVEL_TWO_DIFFICULTY 1.5f;
#define LEVEL_TWO_TOT_CUSTOMERS 60.f;

#define LEVEL_THREE_ARRIVALS 60.f;
#define LEVEL_THREE_DIFFICULTY 2.f;

#define TIME_TO_CHOOSE 5.f
#define INITIAL_HUMOR 500000

enum class Lvl {FIRST, SECOND, THIRD, GAME_END, FIRST_TABLE};

#endif //VIDEOGIOCO_LEVELHEADER_H
