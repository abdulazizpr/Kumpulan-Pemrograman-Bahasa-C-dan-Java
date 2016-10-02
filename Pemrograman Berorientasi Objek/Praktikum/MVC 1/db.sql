create database db_telepon;
use db_telepon;

create table `telepon`(
	kode varchar(15) primary key,
	telp varchar(20)
);

insert into telepon values
('120000001','08123456789'),
('120000002','08123489721'),
('120000003','08927374738');