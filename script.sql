SELECT * FROM universidad.estudiante;
insert into universidad.estudiante(carnet,nombres,apellidos,direccion,telefono,genero,email,fecha_nacimiento)
values('33691221014','Anhya','Jorger','Guatemala','55896347',1,'janhya@gmail.com','2002-03-25');
update universidad.estudiante set genero=0 where id_estudiante='1';
insert into universidad.estudiante(carnet,nombres,apellidos,direccion,telefono,genero,email,fecha_nacimiento)
values('33691221015','Elias','Fidalgo','Guatemala, mixco','23654178',1,'Felias@gmail.com','2001-06-10');
insert into universidad.estudiante(carnet,nombres,apellidos,direccion,telefono,genero,email,fecha_nacimiento)
values('33691221016','Eliza','Guevera','Guatemala zona 10','10475698',0,'geliza@gmail.com','1992-05-09');
insert into universidad.estudiante(carnet,nombres,apellidos,direccion,telefono,genero,email,fecha_nacimiento)
values('33691221017','Dominic','De Leon','Guatemala, mixco','22365414',1,'dldominic@gmail.com','2001-01-15');