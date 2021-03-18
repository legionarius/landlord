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
                "cleanliness": percentage()
                }
        tenants.append(tenant)
    with open('tenants.json', 'w') as out:
        json.dump(tenants, out)

if __name__=="__main__":
    gen_tenants()


