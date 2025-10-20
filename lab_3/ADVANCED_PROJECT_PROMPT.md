# Advanced Glucose Monitoring System - Copilot Project Template Prompt

## Purpose
This prompt demonstrates how GitHub Copilot can be used to kickstart a complete project template for an advanced real-time glucose monitoring system. Copy and paste this prompt into GitHub Copilot Chat to generate a production-ready project structure.

---

## The Prompt

```
Create a complete project template for a real-time continuous glucose monitoring (CGM) system with the following specifications:

## Project Overview
Build a medical-grade real-time glucose monitoring system that:
- Connects to Bluetooth Low Energy (BLE) glucose sensors
- Processes streaming sensor data with sub-second latency
- Implements predictive algorithms for glucose trend forecasting
- Provides real-time alerts and notifications
- Stores data securely with HIPAA compliance considerations
- Offers REST API for integration with mobile apps and healthcare systems
- Includes a web-based dashboard for data visualization

## Technical Stack
- **Backend**: Python 3.11+ with FastAPI
- **Real-time Processing**: asyncio for concurrent sensor handling
- **Database**: PostgreSQL with TimescaleDB extension for time-series data
- **Caching**: Redis for real-time data and session management
- **Message Queue**: RabbitMQ or Apache Kafka for event streaming
- **BLE Communication**: bleak library for Bluetooth sensor communication
- **ML/Prediction**: scikit-learn or TensorFlow Lite for glucose forecasting
- **API Documentation**: OpenAPI/Swagger with FastAPI
- **Monitoring**: Prometheus metrics and Grafana dashboards
- **Testing**: pytest with async support, pytest-cov for coverage
- **Docker**: Multi-stage Dockerfiles with docker-compose for local development

## Project Structure Requirements
Create the following directory structure:

```
glucose-monitoring-system/
├── src/
│   ├── api/                    # FastAPI endpoints
│   │   ├── routes/            # API route handlers
│   │   ├── models/            # Pydantic models
│   │   └── dependencies.py    # Dependency injection
│   ├── core/
│   │   ├── config.py          # Configuration management
│   │   ├── security.py        # Authentication & encryption
│   │   └── database.py        # Database connection pooling
│   ├── sensors/
│   │   ├── ble_manager.py     # BLE device discovery & connection
│   │   ├── sensor_interface.py # Abstract sensor interface
│   │   └── protocols/         # Device-specific protocols
│   ├── processing/
│   │   ├── data_validator.py  # Real-time data validation
│   │   ├── calibration.py     # Sensor calibration algorithms
│   │   └── filters.py         # Signal processing filters
│   ├── analytics/
│   │   ├── statistics.py      # TIR, TBR, TAR, GMI calculations
│   │   ├── predictor.py       # ML-based glucose prediction
│   │   └── pattern_detection.py # Meal/exercise detection
│   ├── alerts/
│   │   ├── alert_engine.py    # Alert rule engine
│   │   ├── notification.py    # Push notifications & webhooks
│   │   └── escalation.py      # Alert escalation logic
│   └── storage/
│       ├── repositories.py    # Data access layer
│       └── migrations/        # Database migrations
├── tests/
│   ├── unit/                  # Unit tests
│   ├── integration/           # Integration tests
│   ├── e2e/                   # End-to-end tests
│   └── fixtures/              # Test data & mocks
├── docs/
│   ├── api/                   # API documentation
│   ├── architecture/          # System design docs
│   └── medical/               # Medical device documentation
├── deployments/
│   ├── docker/
│   ├── kubernetes/
│   └── terraform/
├── monitoring/
│   ├── prometheus/
│   └── grafana/
├── scripts/
│   ├── setup_dev.sh
│   └── generate_test_data.py
├── requirements/
│   ├── base.txt
│   ├── dev.txt
│   └── prod.txt
├── .github/
│   └── workflows/             # CI/CD pipelines
├── docker-compose.yml
├── Dockerfile
├── pyproject.toml
├── README.md
└── .env.example
```

## Key Features to Implement

### 1. BLE Sensor Communication
- Device discovery and pairing
- Multi-sensor support (up to 5 concurrent sensors)
- Automatic reconnection on connection loss
- Battery level monitoring
- Sensor calibration management

### 2. Real-time Data Processing
- Streaming data ingestion with backpressure handling
- Kalman filtering for noise reduction
- Outlier detection and correction
- Rate of change (ROC) calculation
- Missing data interpolation

### 3. Predictive Analytics
- 30-minute glucose prediction using LSTM or Random Forest
- Confidence intervals for predictions
- Hypoglycemia risk assessment
- Meal impact prediction
- Exercise detection and glucose response

### 4. Alert System
- Configurable threshold-based alerts (high/low glucose)
- Predictive alerts (will be high/low in X minutes)
- Rate of change alerts (rapid rise/fall)
- Alert fatigue prevention mechanisms
- Multi-channel notifications (push, SMS, email, webhook)
- Snooze and acknowledgment functionality

### 5. REST API Endpoints
- Patient management (CRUD)
- Sensor registration and pairing
- Real-time glucose readings (WebSocket support)
- Historical data queries with time-range filtering
- Alert configuration and history
- Statistical reports (AGP, TIR, variability)
- Bulk data export (CSV, JSON)

### 6. Security & Compliance
- JWT-based authentication with refresh tokens
- Role-based access control (patient, caregiver, clinician)
- End-to-end encryption for sensor data
- Audit logging for all data access
- PHI data anonymization for analytics
- HIPAA compliance considerations
- Rate limiting and DDoS protection

### 7. Data Storage Schema
- Time-series optimized glucose readings table
- Patient profiles with encrypted PII
- Sensor device registry
- Alert history and acknowledgments
- Calibration events
- User activity logs
- Calculated metrics cache

### 8. Monitoring & Observability
- Prometheus metrics (API latency, sensor connections, alert frequency)
- Structured JSON logging
- Distributed tracing with OpenTelemetry
- Health check endpoints
- Performance profiling hooks

## Code Quality Requirements
- Type hints throughout (mypy strict mode)
- Comprehensive docstrings (Google style)
- 90%+ test coverage
- Pre-commit hooks (black, isort, flake8, mypy)
- GitHub Actions CI/CD pipeline
- Dependency scanning and vulnerability checks

## Configuration Management
- Environment-based configuration (dev, staging, prod)
- Secrets management integration (Azure Key Vault, AWS Secrets Manager)
- Feature flags for gradual rollout
- Configurable alert thresholds per patient

## Documentation to Generate
- README with setup instructions
- API documentation (auto-generated from OpenAPI)
- Architecture decision records (ADRs)
- Deployment guide
- Contributing guidelines
- Medical device compliance checklist

## Development Workflow
- Docker Compose for local development with hot reload
- Sample sensor simulator for testing
- Seed data for development
- Database migration scripts
- Load testing scenarios

## Sample Use Cases to Include
1. Patient monitoring dashboard showing real-time glucose
2. Caregiver receiving low glucose alert with location
3. Clinician reviewing 14-day AGP report
4. API integration with third-party diabetes management app
5. Multi-sensor comparison for redundancy

Please generate:
1. Complete project structure with all directories
2. Key Python files with class definitions and function signatures
3. Docker configuration files
4. Database schema and migration files
5. Sample API endpoint implementations
6. Configuration files (pyproject.toml, requirements files)
7. CI/CD pipeline configuration
8. Comprehensive README with setup instructions
9. Sample .env.example file
10. Basic unit tests for core functionality

Focus on production-ready code with proper error handling, logging, and documentation. Include TODO comments where complex medical algorithms need domain expert input.
```

---

## Usage Instructions for Workshop Participants

### Step 1: Open GitHub Copilot Chat
- Press `Cmd+Shift+I` (Mac) or `Ctrl+Shift+I` (Windows/Linux)
- Or click the Copilot icon in the Activity Bar

### Step 2: Copy and Paste the Prompt
- Copy the entire prompt section above
- Paste it into Copilot Chat
- Press Enter

### Step 3: Review Generated Code
- Copilot will generate the complete project structure
- Review each file and directory created
- Ask follow-up questions to refine specific components

### Step 4: Iterate and Customize
Example follow-up prompts:
- "Add unit tests for the BLE sensor manager"
- "Create a WebSocket endpoint for real-time glucose streaming"
- "Implement the Kalman filter for glucose data smoothing"
- "Add OpenTelemetry integration for distributed tracing"
- "Generate a Kubernetes deployment configuration"

### Step 5: Build and Run
```bash
# Create the project directory
mkdir glucose-monitoring-system
cd glucose-monitoring-system

# Let Copilot generate the files (paste the prompt)

# Once generated, set up the environment
docker-compose up -d

# Run database migrations
docker-compose exec api alembic upgrade head

# Run tests
docker-compose exec api pytest

# Access the API documentation
open http://localhost:8000/docs
```

## Learning Objectives

This exercise demonstrates:
1. **Project Scaffolding**: How Copilot can generate complete project templates
2. **Best Practices**: Following industry standards for Python/FastAPI projects
3. **Architecture**: Proper separation of concerns and modular design
4. **Medical Context**: Incorporating domain-specific requirements
5. **Production Readiness**: Including monitoring, testing, and security from day one
6. **Iteration**: How to refine and expand on Copilot's initial generation

## Key Differences from Workshop Labs

| Aspect | Workshop Labs | Advanced Template |
|--------|--------------|-------------------|
| Language | C | Python |
| Data Source | Simulated/batch | Real-time BLE sensors |
| Architecture | Monolithic | Microservices-ready |
| Storage | In-memory | PostgreSQL + TimescaleDB |
| API | None | REST + WebSocket |
| Deployment | Local binary | Docker + Kubernetes |
| Prediction | Statistical | ML-based |
| Scale | Single user | Multi-tenant |

## Tips for Best Results

1. **Be Specific**: The more detailed your prompt, the better the output
2. **Iterate**: Use follow-up questions to refine specific areas
3. **Verify**: Always review generated code for security and correctness
4. **Context**: Reference medical device standards if applicable
5. **Test Early**: Ask Copilot to generate tests alongside implementation

## Extended Prompts to Try

After the initial generation, try these advanced prompts:

```
"Add integration with the Abbott FreeStyle Libre 3 CGM sensor protocol"

"Implement a machine learning pipeline for predicting hypoglycemic events 60 minutes in advance"

"Create a FHIR-compliant API for integration with electronic health records"

"Add multi-tenancy support for healthcare organizations managing multiple patients"

"Implement a pub/sub pattern using Redis for real-time glucose data distribution"

"Generate load testing scenarios using Locust for 10,000 concurrent sensor connections"

"Add FDA and CE Mark compliance documentation templates"

"Create a React dashboard for real-time glucose monitoring with WebSocket connection"
```

## Additional Resources

- **FastAPI Documentation**: https://fastapi.tiangolo.com/
- **TimescaleDB for Healthcare**: https://docs.timescale.com/
- **BLE with Python**: https://github.com/hbldh/bleak
- **Medical Device Software Standards**: IEC 62304, ISO 13485
- **HIPAA Compliance**: https://www.hhs.gov/hipaa/

---

## Discussion Points for Workshop

1. How does Copilot understand medical domain requirements?
2. What architectural decisions did Copilot make and why?
3. How can you validate AI-generated code for safety-critical systems?
4. What's the balance between speed of development and code quality?
5. How to use Copilot while maintaining compliance requirements?
