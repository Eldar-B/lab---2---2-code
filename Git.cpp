#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <stdio.h>
#include <ctype.h>

int i = 0;
float size = 0;
 
void update();

struct pricing_policy
{
	char update[30] = "last price update 25.11.2024";
	float field_cost = 500000;

	struct plowing
	{
		float time_plowing = 5;
		float cost_plowing = 13000;
	}pl;
	struct cultivation
	{
		float time_cultivation = 3;
		float cost_cultivation = 11500;
	}cl;
	struct rolling
	{
		float time_rolling = 2;
		float cost_rolling = 10000;
	}rl;
	struct fertilization
	{
		float cost_fertilization = 11500;
		float time_fertilization = 1;
		float volume_mineral_fertilizers = 100;
	}fl;

	float final_time = pl.time_plowing + cl.time_cultivation + rl.time_rolling + fl.time_fertilization;
	float final_cost = pl.cost_plowing + cl.cost_cultivation + rl.cost_rolling + fl.cost_fertilization;
}pp;

struct field_characteristics
{
	float field_cost = 0;

	struct plowing
	{
		float time_plowing = 0;
		float cost_plowing = 0;
	}pl;
	struct cultivation
	{
		float time_cultivation = 0;
		float cost_cultivation = 0;
	}cl;
	struct rolling
	{
		float time_rolling = 0;
		float cost_rolling = 0;
	}rl;
	struct fertilization
	{
		float cost_fertilization = 0;
		float time_fertilization = 0;
		float volume_mineral_fertilizers = 0;
	}fl;

	float final_time = 0;
	float final_cost = 0;
}field;

void update()
{
	field.field_cost = pp.field_cost * size;
	field.pl.time_plowing = pp.pl.time_plowing * size;
	field.pl.cost_plowing = pp.pl.cost_plowing * size;
	field.cl.time_cultivation = pp.cl.time_cultivation * size;
	field.cl.cost_cultivation = pp.cl.cost_cultivation * size;
	field.rl.time_rolling = pp.rl.time_rolling * size;
	field.rl.cost_rolling = pp.rl.cost_rolling * size;
	field.fl.cost_fertilization = pp.fl.cost_fertilization * size;
	field.fl.time_fertilization = pp.fl.time_fertilization * size;
	field.fl.volume_mineral_fertilizers = pp.fl.volume_mineral_fertilizers * size;
	field.final_time = pp.final_time * size;
	field.final_cost = pp.final_cost * size;
}

int main() 
{
	int game_status = 0;
	do
	{
		printf("================================\n");
		printf("Add field | Show info | Hide info\n");
		printf("================================\n");
		printf("    1     |     2     |    3\n");
		printf("================================\n");
		if (game_status == 2)
		{
			printf("Field size: %.2f He\n", size);                            //Размер поля в Га
			printf("Field cost: %.2f rub\n", field.field_cost);                  //Цена земли
			printf("================================\n");
			printf("Plowing time: %.2f h\n", field.pl.time_plowing);             //Вспашка
			printf("Cultivation time: %.2f h\n", field.cl.time_cultivation);     //Культивация                  
			printf("Rolling time: %.2f h\n", field.rl.time_rolling);             //Прикатывание
			printf("Fertilization time: %.2f h\n", field.fl.time_fertilization); //Удобрения
			printf("Final time: %.2f h\n", field.final_time);
			printf("================================\n");
			printf("Plowing cost: %.2f rub\n", field.pl.cost_plowing);
			printf("Cultivation cost: %.2f rub\n", field.cl.cost_cultivation);
			printf("Rolling cost: %.2f rub\n", field.rl.cost_rolling);
			printf("Fertilization cost: %.2f rub\n", field.fl.cost_fertilization);
			printf("Final cost: %.2f rub\n", field.final_cost);
			printf("================================\n");
			printf("Additional(volume of mineral fertilizers: %.2f L)\n", field.fl.volume_mineral_fertilizers);
			printf("================================\n");
			printf("%s\n", pp.update);
		}
		scanf_s("%d", &game_status);
		if (game_status == 1)
		{
			system("cls");
			printf("Enter field size in He\n");
			scanf_s("%f", &size);
			update();
		}
		system("cls");
	} while (true);
}
