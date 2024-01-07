use tokio::time::{sleep,Duration};
async fn execute_order(order:&str)->Result<(),&'static str>{
    sleep(Duration::from_micros(100)).await;
    if(order.contains("buy")){
        Ok(())
        else{
            Err("Order failed")
        }
    }

}
#[tokio::main]
async fn main(){
    let orders=vec!["buy AAPL","buy Google","buy MSFT"];
    for order in orders{
        let result=execute_order(order).await;
        match result{
            Okk(())=>println!("ORder done :{}",order);
            Err(e)=>println!("ORder failed :{}",order);
        }
    }
}