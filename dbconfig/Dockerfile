FROM postgres:latest
LABEL authors="grtsinry43"

ENV POSTGRES_DB=simple12306
ENV POSTGRES_USER=root
ENV POSTGRES_PASSWORD=root

COPY init_table.sql /docker-entrypoint-initdb.d/
COPY insert_data.sql /docker-entrypoint-initdb.d/

EXPOSE 5432