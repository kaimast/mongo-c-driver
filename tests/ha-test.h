/*
 * Copyright 2013 10gen Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#ifndef HA_TEST_H
#define HA_TEST_H


#include <bson.h>


BSON_BEGIN_DECLS


typedef struct _ha_replica_set_t ha_replica_set_t;
typedef struct _ha_node_t        ha_node_t;


ha_replica_set_t *ha_replica_set_new              (const char       *name);
ha_node_t        *ha_replica_set_add_arbiter      (ha_replica_set_t *replica_set,
                                                   const char       *name);
ha_node_t        *ha_replica_set_add_replica      (ha_replica_set_t *replica_set,
                                                   const char       *name);
void              ha_replica_set_start            (ha_replica_set_t *replica_set);
void              ha_replica_set_shutdown         (ha_replica_set_t *replica_set);
void              ha_replica_set_destroy          (ha_replica_set_t *replica_set);
void              ha_replica_set_wait_for_healthy (ha_replica_set_t *replica_set);


void              ha_node_kill                    (ha_node_t        *node);
void              ha_node_restart                 (ha_node_t        *node);


BSON_END_DECLS


#endif /* HA_TEST_H */