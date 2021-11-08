#pragma once
#include <d3dx9.h>
#include <vector>

using namespace std;

#define  MAX_NAME_SIZE 16

struct sc_other_client_info //�α��ν� Ȥ�� Ÿ �÷��̾� �α��ν� �ٸ� Ŭ���̾�Ʈ ���� ����
{
	unsigned char size;
	char        type;
	int           id;
	char          name[MAX_NAME_SIZE];
	D3DXVECTOR4   body_color;
	D3DXVECTOR4   cloth_color;
	bool          is_ready;
};

struct cs_change_color
{
	unsigned char size;
	char        type;
	int           id;
	D3DXVECTOR4   body_color;
	D3DXVECTOR4   cloth_color;
};

struct sc_change_color
{
	unsigned char size;
	char        type;
	int           id;
	D3DXVECTOR4   body_color;
	D3DXVECTOR4   cloth_color;
};

struct cs_ready
{
	unsigned char size;
	char        type;
	int           id;
	bool          is_ready;
};

struct sc_ready
{
	unsigned char size;
	char        type;
	int           id;
	bool          is_ready;
};

struct sc_game_start // 3���� ��� �غ� ���� ������ ����
{
	unsigned char size;
	char        type;


};

enum WEAPON
{


};
struct Weapon
{
	WEAPON      e_weapon;
	float       weapon_length;
};

enum BULLET
{


};
struct Bullet
{

	//Ŭ�� ȭ����

};

enum DIR { DIR_LT, DIR_L, DIR_LB, DIR_CT, DIR_C, DIR_CB, DIR_RT, DIR_R, DIR_RB };
enum STATE { IDLE, RUN, DODGE, DEAD, HAPPY };

struct Item
{
	//id �ʿ��Ѱ�?
	D3DXVECTOR2   v_position;
	WEAPON        e_weapon;     //���� ���� (�����ۿ��� ����ܿ� �ٸ� �͵� ������ �Ϸ��� ���� �ʿ�)
};

struct Player  //player ����
{
	char          id;
	char          name[MAX_NAME_SIZE];
	D3DXVECTOR4   body_color;
	D3DXVECTOR4   cloth_color;

	D3DXVECTOR2   v_position;
	D3DXVECTOR2   v_look;
	DIR           e_direction;
	STATE         e_state;
	char          health;
	bool          is_invincible;
	WEAPON        e_weapon;
	float         cool_time;
};

struct GameStatePlayer   //game_state ���ۿ� �ʿ���� ������ ������ ����ü
{
	char          id;

	D3DXVECTOR2   v_position;
	D3DXVECTOR2   v_look;
	DIR           e_direction;
	STATE         e_state;
	char          health;
	bool          is_invincible;
	WEAPON        e_weapon;
	float         cool_time;
};

struct sc_game_state  //�� �����Ӹ��� ���� ��ü ���� ����
{
	unsigned char size;
	char        type;

	//Player info
	GameStatePlayer player[3];
	vector<Item>    items;
	vector<Bullet>  bullets;
};
