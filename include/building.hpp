#pragma once

#include "sdl2.hpp"

#include <memory>
#include <string>
#include <set>

class Building
{
public:
	Building(std::string const& _img, sdl2::Dimension const _dim,
		int const _height_d, int const _cost_gold, int const _cost_wood, int const _cost_stone);

public:
	void display_building(bool const transparent) const;
	void display_backdrop(SDL_Color const& clr) const;
	void display_placement_options() const;
	bool is_pressed(int x, int y) const;

	virtual void add_resources();
	virtual bool is_display_cap();
	virtual void display_item();

public:
	virtual std::shared_ptr<Building> create_building() const;
	
public:
	bool operator < (Building const& _building) const;
	bool operator == (Building const& _building) const;
	bool operator () (Building const& _b1, Building const& _b2) const;

public:
	std::string img;
	sdl2::Dimension dim;
	int height_d;
	int cost_gold, cost_wood, cost_stone;
};

enum class ProdType
{
	GOLD,
	WHEAT,
	WOOD,
	STONE,
	IRON
};

class ProdBuilding : public Building
{
public:
	ProdBuilding(std::string const& _img, sdl2::Dimension const _dim,
		int const _height_d, int const _cost_gold, int const _cost_wood, int const _cost_stone,
		ProdType const _type, int const _rate, int const _display_cap, int const _storage_cap);

public:
	void add_resources() override;
	bool is_display_cap() override;
	void display_item() override;

public:
	std::shared_ptr<Building> create_building() const override;

private:
	ProdType type;
	int rate;
	int amount;

	int display_cap;
	int storage_cap;
};