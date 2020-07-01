use kodokan_database;
show tables;
insert into users(login, email, name, surname, hashed_pswd) values ("piter", "p.p.b.pietro@gmail.com", "Piotr", "Bosowski", "HASH123");
insert into users(login, email, name, surname, hashed_pswd) values ("luki", "luki123@gmail.com", "Łukasz", "Ważny", "HASH234");
insert into users(login, email, name, surname, hashed_pswd) values ("danio", "danio987@gmail.com", "Daniel", "Kaleta", "HASH345");
insert into users(login, email, name, surname, hashed_pswd) values ("pietro", "pietuhl@gmail.com", "Piotr", "Uhl", "HASH456");
select * from subscriptions;

drop table users, subscription_types, subscriptions, kodokan_info, ostatni_paragon;

select * from kodokan_info;

select * from subscription_types;
delete from subscription_types where id=0;
insert into subscription_types(price, length, name) values (10, 1, "jednorazowy");
insert into subscription_types(price, length, name) values (100, 30, "miesieczny");
insert into subscription_types(price, length, name) values (200, 90, "kwartalny");
insert into subscription_types(price, length, name) values (600, 365, "roczny");

insert into kodokan_info(nazwa_firmy, adres, nip) values("Kodokan sp. z o.o.", "Gliwice 7/5", "14466367");

select * from ostatni_paragon;
insert into ostatni_paragon(ostatni_nr_par, data_ostatniego_par)values(17, "2020-07-01");

drop table subscriptions;
insert into subscriptions(starting_date, expiring_date, payment_method, users_id, subscription_types_id) values ("1997-12-12 00:00:05", "1998-12-12 23:52:59", "card", 2, 8);
select * from users;

select * from subscription_types;