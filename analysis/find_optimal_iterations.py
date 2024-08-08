import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from statsmodels.graphics.tsaplots import plot_acf
from scipy import stats

def read_data(file_path):
    # Read the CSV file
    df = pd.read_csv(file_path, header=None)

    # Flatten the dataframe into a single column
    iteration_times = df.values.flatten()

    # Create a new dataframe with a single column
    df = pd.DataFrame({'iteration_time': iteration_times})

    return df

def plot_run_sequence(data):
    plt.figure(figsize=(12, 6))
    plt.plot(data.index, data['iteration_time'])
    plt.title('Run Sequence Plot')
    plt.xlabel('Iteration')
    plt.ylabel('Time')
    plt.show()

def plot_lag(data):
    plt.figure(figsize=(12, 6))
    plt.scatter(data['iteration_time'][:-1], data['iteration_time'][1:])
    plt.title('Lag Plot')
    plt.xlabel('Time(t)')
    plt.ylabel('Time(t+1)')
    plt.show()

def plot_autocorrelation(data):
    plot_acf(data['iteration_time'])
    plt.title('Autocorrelation Plot')
    plt.show()

def find_stable_point(data):
    # This is a simple heuristic. You might need to adjust this based on your data.
    window = 20
    rolling_mean = data['iteration_time'].rolling(window=window).mean()
    rolling_std = data['iteration_time'].rolling(window=window).std()

    stable_point = window
    for i in range(window, len(data)):
        if (abs(rolling_mean[i] - rolling_mean[i-1]) < rolling_std[i] * 0.1 and
            abs(rolling_std[i] - rolling_std[i-1]) < rolling_std[i] * 0.1):
            stable_point = i
            break

    return stable_point

def calculate_variance_estimates(data, stable_point):
    stable_data = data.iloc[stable_point:]

    # Variance at iteration level
    T_1_squared = np.var(stable_data['iteration_time'], ddof=1)

    # Variance at execution level (assuming each execution is 10 iterations)
    execution_means = stable_data['iteration_time'].groupby(stable_data.index // 10).mean()
    T_2_squared = np.var(execution_means, ddof=1) - T_1_squared / 10

    return T_1_squared, T_2_squared

def optimize_iteration_count(T_1_squared, T_2_squared, c_1, c_2, desired_precision):
    r_1 = int(np.ceil(np.sqrt((c_2 * T_1_squared) / (c_1 * T_2_squared))))

    total_iterations = r_1
    while True:
        half_width = stats.t.ppf(0.975, total_iterations - 1) * np.sqrt(T_2_squared / total_iterations)
        relative_half_width = half_width / np.mean(data['iteration_time'])
        if relative_half_width <= desired_precision:
            break
        total_iterations += 1

    return r_1, total_iterations

# Main analysis
file_path = 'Results/Wasmtime/averageVector_float_262144.csv'
data = read_data(file_path)

# plot_run_sequence(data)
# plot_lag(data)
# plot_autocorrelation(data)

stable_point = find_stable_point(data)
print(f"Stable point found at iteration: {stable_point}")

T_1_squared, T_2_squared = calculate_variance_estimates(data, stable_point)
print(f"Variance estimate at iteration level: {T_1_squared}")
print(f"Variance estimate at execution level: {T_2_squared}")

# Assuming costs. You might need to adjust these based on your setup.
c_1 = 1  # Cost of one iteration
c_2 = 10  # Cost of one execution (assumed to be 10 iterations)

desired_precision = 0.01  # 1% relative half-width

r_1, total_iterations = optimize_iteration_count(T_1_squared, T_2_squared, c_1, c_2, desired_precision)

print(f"Optimal number of iterations per execution: {r_1}")
print(f"Total number of iterations needed for {desired_precision*100}% precision: {total_iterations}")

current_iterations = len(data)
if current_iterations >= total_iterations:
    print(f"Your current {current_iterations} iterations are sufficient for your desired precision.")
else:
    print(f"You need {total_iterations} iterations to achieve your desired precision. Your current {current_iterations} iterations are not sufficient.")