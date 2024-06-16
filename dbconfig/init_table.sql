create table public.orders
(
    id         serial
        primary key,
    user_id    integer                 not null,
    ticket_id  integer                 not null,
    status     integer                 not null,
    created_at timestamp default now() not null,
    user_info  json                    not null,
    type       integer
);

alter table public.orders
    owner to root;

create table public.tickets
(
    id         serial
        primary key,
    title      varchar(255)   not null,
    "from"     varchar(255)   not null,
    "to"       varchar(255)   not null,
    start_date timestamp      not null,
    end_date   timestamp      not null,
    price      numeric(10, 2) not null,
    train_type integer        not null,
    type_1     integer        not null,
    type_2     integer,
    type_3     integer,
    type_4     integer
);

alter table public.tickets
    owner to root;

create table public.users
(
    user_id        serial
        primary key,
    username       varchar(50) not null,
    password       varchar(50) not null,
    email          varchar(50),
    phone          varchar(50),
    gender         varchar(50),
    region         varchar(50),
    created_at     timestamp default CURRENT_TIMESTAMP,
    is_verified    boolean   default false,
    is_student     boolean   default false,
    discount_times integer   default 0
);

alter table public.users
    owner to root;

