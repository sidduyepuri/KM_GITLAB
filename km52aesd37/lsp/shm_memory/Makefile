all: 1_prod_cons_rel 2_prod_rel 2_cons_rel 3_producer 3_consumer
1_prod_cons_rel: 
	gcc 1_prod_cons_rel.c -o prod_cons_rel -lpthread
2_prod_rel: 
	gcc 2_prod_rel.c -o produce -lpthread
2_cons_rel: 
	gcc 2_cons_rel.c -o consume -lpthread
3_producer:
	gcc 3_producer.c -o producer -lpthread
3_consumer:
	gcc 3_consumer.c -o consumer -lpthread

clean:
	rm prod_cons_rel produce consume producer consumer
