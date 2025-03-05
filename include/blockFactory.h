#ifndef BLOCKFACTORY_H
#define BLOCKFACTORY_H

#include "headers.h"
#include "objectMap.h"
#include "object.h"
#include "component.h"
#include "unitComp.h"
#include "transformComp.h"

void create_unbreakableBlock(Vector2i pos, char symbol);

void create_block(Vector2i pos, char symbol, int hp);

#endif
