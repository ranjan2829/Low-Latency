use tokio::time::{sleep, Duration};

async fn execute_order(order: &str) -> Result<(), &'static str> {
    // Simulate order execution delay
    sleep(Duration::from_micros(100)).await;

    // Simulate order execution success or failure
    if order.contains("buy") {
        Ok(())
    } else {
        Err("Order execution failed")
    }
}

#[tokio::main]
async fn main() {
    let orders = vec!["buy AAPL", "sell GOOGL", "buy MSFT"];

    for order in orders {
        let result = execute_order(order).await;

        match result {
            Ok(()) => println!("Order executed successfully: {}", order),
            Err(e) => println!("Order execution failed for {}: {}", order, e),
        }
    }
}
