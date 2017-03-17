#include "stdafx.h"

short sinTable[] =
{
	0, 100, 201, 301, 402, 502, 603, 703, 804, 
	904, 1005, 1105, 1206, 1306, 1407, 1507, 1607, 
	1708, 1808, 1909, 2009, 2109, 2210, 2310, 2410, 
	2510, 2611, 2711, 2811, 2911, 3011, 3111, 3211, 
	3311, 3411, 3511, 3611, 3711, 3811, 3911, 4011, 
	4110, 4210, 4310, 4409, 4509, 4609, 4708, 4808, 
	4907, 5006, 5106, 5205, 5304, 5403, 5503, 5602, 
	5701, 5800, 5898, 5997, 6096, 6195, 6294, 6392, 
	6491, 6589, 6688, 6786, 6884, 6983, 7081, 7179, 
	7277, 7375, 7473, 7571, 7669, 7766, 7864, 7961, 
	8059, 8156, 8254, 8351, 8448, 8545, 8642, 8739, 
	8836, 8933, 9029, 9126, 9223, 9319, 9415, 9512, 
	9608, 9704, 9800, 9896, 9991, 10087, 10183, 10278, 
	10374, 10469, 10564, 10659, 10754, 10849, 10944, 11039, 
	11133, 11228, 11322, 11416, 11511, 11605, 11699, 11793, 
	11886, 11980, 12073, 12167, 12260, 12353, 12446, 12539, 
	12632, 12725, 12817, 12910, 13002, 13094, 13186, 13278, 
	13370, 13462, 13554, 13645, 13736, 13828, 13919, 14010, 
	14100, 14191, 14282, 14372, 14462, 14552, 14642, 14732, 
	14822, 14912, 15001, 15090, 15180, 15269, 15357, 15446, 
	15535, 15623, 15712, 15800, 15888, 15976, 16063, 16151, 
	16238, 16325, 16413, 16499, 16586, 16673, 16759, 16846, 
	16932, 17018, 17104, 17189, 17275, 17360, 17445, 17530, 
	17615, 17700, 17784, 17869, 17953, 18037, 18121, 18204, 
	18288, 18371, 18454, 18537, 18620, 18703, 18785, 18868, 
	18950, 19032, 19113, 19195, 19276, 19358, 19439, 19519, 
	19600, 19681, 19761, 19841, 19921, 20001, 20080, 20159, 
	20239, 20318, 20396, 20475, 20553, 20631, 20709, 20787, 
	20865, 20942, 21020, 21097, 21173, 21250, 21326, 21403, 
	21479, 21555, 21630, 21706, 21781, 21856, 21931, 22005, 
	22080, 22154, 22228, 22301, 22375, 22448, 22521, 22594, 
	22667, 22740, 22812, 22884, 22956, 23027, 23099, 23170, 
	23241, 23312, 23382, 23453, 23523, 23593, 23662, 23732, 
	23801, 23870, 23939, 24007, 24075, 24144, 24211, 24279, 
	24346, 24414, 24480, 24547, 24614, 24680, 24746, 24812, 
	24877, 24943, 25008, 25073, 25137, 25201, 25266, 25330, 
	25393, 25457, 25520, 25583, 25645, 25708, 25770, 25832, 
	25894, 25955, 26016, 26077, 26138, 26199, 26259, 26319, 
	26379, 26438, 26498, 26557, 26615, 26674, 26732, 26790, 
	26848, 26905, 26963, 27020, 27076, 27133, 27189, 27245, 
	27301, 27356, 27411, 27466, 27521, 27576, 27630, 27684, 
	27737, 27791, 27844, 27897, 27949, 28002, 28054, 28106, 
	28157, 28208, 28259, 28310, 28361, 28411, 28461, 28511, 
	28560, 28609, 28658, 28707, 28755, 28803, 28851, 28898, 
	28946, 28993, 29039, 29086, 29132, 29178, 29223, 29269, 
	29314, 29359, 29403, 29447, 29491, 29535, 29578, 29621, 
	29664, 29707, 29749, 29791, 29833, 29874, 29915, 29956, 
	29997, 30037, 30077, 30117, 30156, 30196, 30235, 30273, 
	30312, 30350, 30387, 30425, 30462, 30499, 30535, 30572, 
	30608, 30644, 30679, 30714, 30749, 30784, 30818, 30852, 
	30886, 30919, 30952, 30985, 31018, 31050, 31082, 31114, 
	31145, 31176, 31207, 31237, 31268, 31298, 31327, 31357, 
	31386, 31414, 31443, 31471, 31499, 31526, 31554, 31581, 
	31607, 31634, 31660, 31685, 31711, 31736, 31761, 31785, 
	31810, 31834, 31857, 31881, 31904, 31927, 31949, 31971, 
	31993, 32015, 32036, 32057, 32078, 32098, 32118, 32138, 
	32157, 32176, 32195, 32214, 32232, 32250, 32268, 32285, 
	32302, 32319, 32335, 32351, 32367, 32383, 32398, 32413, 
	32427, 32442, 32456, 32469, 32483, 32496, 32509, 32521, 
	32533, 32545, 32557, 32568, 32579, 32589, 32600, 32610, 
	32619, 32629, 32638, 32647, 32655, 32663, 32671, 32679, 
	32686, 32693, 32700, 32706, 32712, 32718, 32723, 32728, 
	32733, 32737, 32741, 32745, 32749, 32752, 32755, 32758, 
	32760, 32762, 32764, 32765, 32766, 32767, 32767, 32767
};

void genSinus(float f, float a, int length, short data[], int *phase)
{
	int delta = 4*512*f + 0.5;
	int k = *phase;
	for(int i = 0; i < length; i++)
	{
		k =  k & (4*512-1);
		if( k > 512 && k <= 2*512)
			data[i] = a*sinTable[512*2-k];
		else if(k > 2*512 && k <= 3*512)
			data[i] = - a*sinTable[k - 512*2];
		else if(k > 3*512)
 			data[i] = - a*sinTable[4*512 - k];
		else
			data[i] = a*sinTable[k];
		data[i] /= 10;
		k += delta;
	}
	*phase = k;
}