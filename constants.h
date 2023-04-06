#pragma once

static const int CODE_EMPTY=0;
const int CODE_START=-100;
const int CODE_DESTINATION=-200;
static const int CODE_BARRIER=-300;
const int CODE_PATH=-500;
const int CODE_SECOND_PATH=-600;
const int CODE_VIEWED=-700;
const int CODE_POI=1;//From 1 to 9

//const double H_WEIGHT=0.8;
//const double SIGMA=1;
//const double FILTER_WEIGHT=10;

const double SIGMA=1;
const double H_WEIGHT=0.8;
const double FILTER_WEIGHT=2;

//const double FILTER_WEIGHT=10;
//const double SIGMA=0.5;
//const double H_WEIGHT=0.5;

//const double SIGMA=1;
//const double H_WEIGHT=0.6;
//const double FILTER_WEIGHT=50;

//const double SIGMA=1;
//const double H_WEIGHT=0.51;
//const double FILTER_WEIGHT=30;

const double POI_WEIGHT=5;
const double DIST_WEIGHT=1;

const int COLOR_EMPTY=176;
const int COLOR_POI=64;
const int COLOR_PATH=224;
const int COLOR_BARRIER=112;
const int COLOR_START=160;
const int COLOR_DESTINATION=96;
const int COLOR_VIEWED=48;
const int COLOR_SECOND_PATH=80;
const int COLOR_STANDARD=15;

const char PRINTING_CHAR=' ';
