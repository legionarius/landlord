#! /usr/bin/env python3
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2021 bogdan <bogdan@linux-96tt>
#
# Distributed under terms of the MIT license.

import names
import json
from random import randint, choice

men_pic = "asset/Tenant/picture/men1.png"
women_pic = "asset/Tenant/picture/woman1.png"
leasing_duration_array = [1, 6 , 12]

def age():
    return randint(18, 99)

def firstname(gender):
    return names.get_first_name(gender=gender)

def lastname():
    return names.get_last_name()

def percentage():
    return randint(0,90)

def gender():
    return choice(['male','female'])

def picture(gender):
    if gender == 'male':
        return men_pic
    else:
        return women_pic

def leasing_duration():
    return leasing_duration_array[randint(0,2)]

def gen_tenants(n = 50):
    tenants = []
    for i in range(1,n+1):
        sex = gender()
        tenant = {
                "id": i,
                "firstname": firstname(sex),
                "lastname": lastname(),
                "age": age(),
                "description": "",
                "picture_path": picture(sex),
                "confidence": percentage(),
                "cleanliness": percentage(),
                "leasing_duration": leasing_duration()
                }
        tenants.append(tenant)
    with open('tenants.json', 'w') as out:
        json.dump(tenants, out)

def edit_desc():
    f = open('tenants.json', 'r')
    data = json.load(f)
    f.close()
    for tenant in data:
        if not tenant['description']:
            print(json.dumps(tenant, indent=4))
            tenant['description'] = input('Enter description: ')
    with open('tenants.json', 'w') as out:
        json.dump(data, out)


if __name__=="__main__":
    gen_tenants()
    edit_desc()


